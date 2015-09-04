#include "AIExport.h"

#include "ExternalAI/Interface/SSkirmishAICallback.h"
//#include "ExternalAI/Interface/AISCommands.h"
#include "send_to.h"
#include "events.h"
#include "callbacks.h"
#include "commands.h"


#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "erl_interface.h"
#include "ei.h"

#define BUFSIZE 1000
#define COMM_TMO 10

#define HQ_NODE "hq"
#define COMMROOM "commroom"
#define NODE_NAME_PREFIX "erlang_ai"
#define COOKIE_PREFIX "erlang_ai"

#define MAX_TEAM_COUNT 4


int frame = -1;
char node_names[MAX_TEAM_COUNT][100];

char cookies[MAX_TEAM_COUNT][100];

ei_cnode ecs[MAX_TEAM_COUNT];
char hq_nodes[MAX_TEAM_COUNT][100];
int uplinks[MAX_TEAM_COUNT];
const struct SSkirmishAICallback* callbacks[MAX_TEAM_COUNT];


EXPORT(int) init(int team_id, const struct SSkirmishAICallback* new_callback) {
    callbacks[team_id] = new_callback;

    fprintf(stdout, "sync version: %s\n", callbacks[team_id]->Engine_Version_getFull(team_id));

    fprintf(stdout, "\n\n\t\tStarting up Erlang CNode, Team %i\n\n", team_id);

    sprintf(node_names[team_id], "%s%i", NODE_NAME_PREFIX, team_id);
    sprintf(cookies[team_id], "%s%i", COOKIE_PREFIX, team_id);

    if (ei_connect_init(&ecs[team_id], node_names[team_id], cookies[team_id], team_id) < 0) {
        fprintf(stderr, "ERROR when initializing: %d", erl_errno);
        exit(-1);
    }

    sprintf(hq_nodes[team_id], "%s%i@%s", HQ_NODE, team_id, ei_thishostname(&ecs[team_id]));

    fprintf(stdout, "this node: %s\n", ei_thisnodename(&ecs[team_id]));
    // fprintf(stdout, "host: %s\n", ei_thishostname(&ec));
    fprintf(stdout, "  hq node: %s\n", hq_nodes[team_id]);
    fprintf(stdout, "   cookie: %s\n", cookies[team_id]);

    return 0;
}


int check_uplink(int team_id) {
    int uplink = uplinks[team_id];
    if (uplink <= 0) {
        ei_cnode ec = ecs[team_id];
        char* hq_node = hq_nodes[team_id];
        uplink = ei_connect_tmo(&ec, hq_node, COMM_TMO);
        printf("uplink after 1st connect: %i\n", uplink);
        if (uplink <= 0) {
            if (frame % 600 == 0) {
                fprintf(stderr, "uplink still not available\n");
            }
            return -1;
        }
        fprintf(stdout, "uplink established on channel %i\n", uplink);
        uplinks[team_id] = uplink;
    }
    return 0;
}


EXPORT(int) send_to_hq(int team_id, ei_x_buff buff) {
    int result = 0;
    if (check_uplink(team_id) >= 0) {
        //fprintf(stdout, "[%s] --[%i]--> hq\n", ei_thishostname(&ec), uplink);
        int uplink = uplinks[team_id];
        ei_cnode ec = ecs[team_id];
        if (ei_reg_send_tmo(&ec, uplink, COMMROOM, buff.buff, buff.index, COMM_TMO) < 0) {
            fprintf(stderr, "\tsend failed: %i\n", erl_errno);
            result = -1;
        }
    } else {
        printf("no uplink?!\n");
    }
    ei_x_free(&buff);
    return result;
}

EXPORT(int) send_to_pid(int team_id, erlang_pid* pid, ei_x_buff buff) {
    int result = 0;
    if (check_uplink(team_id) >= 0) {
        int uplink = uplinks[team_id];
        if (ei_send_tmo(uplink, pid, buff.buff, buff.index, COMM_TMO) < 0) {
            fprintf(stderr, "\tsend failed: %i\n", erl_errno);
            result = -1;
        }
    } else {
        printf("no uplink?!\n");
    }
    ei_x_free(&buff);
    return result;
}

EXPORT(int) answer(int team_id, erlang_pid* pid, char* what) {
    ei_x_buff sendbuff;
    ei_x_new_with_version(&sendbuff);
    ei_x_encode_atom(&sendbuff, what);
    return send_to_pid(team_id, pid, sendbuff);
}

EXPORT(int) answer_ok(int team_id, erlang_pid* pid) {
    return answer(team_id, pid, "ok");
}

EXPORT(int) answer_error(int team_id, erlang_pid* pid) {
    return answer(team_id, pid, "error");
}

int send_event(int team_id, int topic, const void* data) {
    int uplink = uplinks[team_id];
    fprintf(stdout, "[%s] topic %i --[%i]--> %s\n", cookies[team_id], topic, uplink, hq_nodes[team_id]);

    erl_errno = 0;
    ei_x_buff sendbuf;
    ei_x_new_with_version(&sendbuf);
    ei_x_encode_tuple_header(&sendbuf, 3);
    ei_x_encode_atom(&sendbuf, "event");

    if (add_event_data(&sendbuf, topic, data) < 0) {
        printf("cannot add event data?!\n");
        ei_x_free(&sendbuf);
        return 1;
    }

    return send_to_hq(team_id, sendbuf);
}


int send_pong(int team_id, erlang_pid pid) {
    ei_x_buff buff;
    ei_x_new_with_version(&buff);
    ei_x_encode_atom(&buff, "pong");
    return send_to_pid(team_id, &pid, buff);
}


int send_tick(int team_id, int frame) {
    ei_cnode ec = ecs[team_id];
    ei_x_buff buff;
    ei_x_new_with_version(&buff);
    ei_x_encode_tuple_header(&buff, 3);
    ei_x_encode_atom(&buff, "tick");
    ei_x_encode_long(&buff, frame);
    ei_x_encode_pid(&buff, ei_self(&ec));
    return send_to_hq(team_id, buff);
}


int check_for_message_from_hq(int team_id) {
    if (check_uplink(team_id) < 0) {
        return 0;
    }

    int uplink = uplinks[team_id];

    erl_errno = 0;
    erlang_msg msg;
    ei_x_buff recvbuf;
    ei_x_new(&recvbuf);

    int got = ei_xreceive_msg_tmo(uplink, &msg, &recvbuf, COMM_TMO);
    char message[24] = "";
    int version, arity;

    if (got == ERL_TICK) {
        // ignore
    } else if (got == ERL_ERROR) {
        switch (erl_errno) {
            case EAGAIN:
                break;
            case EMSGSIZE:
                erl_err_quit("msgsize!");
                break;
            case EIO:
                fprintf(stderr, "IO-Error?!\n");
                uplinks[team_id] = -1;
                break;
            case ETIMEDOUT:
                break;
        }
    } else {
        recvbuf.index = 0;
        ei_decode_version(recvbuf.buff, &recvbuf.index, &version);
        ei_decode_tuple_header(recvbuf.buff, &recvbuf.index, &arity);
        ei_decode_atom(recvbuf.buff, &recvbuf.index, message);

        printf("received: %s <--[%i]-- /%i, 0:'%s'\n", msg.toname, uplink, arity, message);
    }
    if (strcmp(message, "ping") == 0) {
        erlang_pid from;
        ei_decode_pid(recvbuf.buff, &recvbuf.index, &from);
        send_pong(team_id, from);
    }
    if (strcmp(message, "callback") == 0) {
        return handle_callback(team_id, callbacks[team_id], recvbuf);
    }
    if (strcmp(message, "command") == 0) {
        return handle_command(team_id, callbacks[team_id], recvbuf);
    }

    return 0;
}


EXPORT(int) handleEvent(int team_id, int topic, const void* data) {
    if (topic == 3) {
        frame = *((int*)data);  // I 'love' pointers :o)
        if (frame == 1) {
            fprintf(stdout, "\n                LET THE WAR BEGIN!\n\n");
        }
        if (frame % 600 == 0) {
            return send_tick(team_id, frame);
        }
        if (frame % 10 == 0) {
            return check_for_message_from_hq(team_id);
        }
        return 0;
    }

    return send_event(team_id, topic, data);
}
