
/* GENERATED FILE, DO NOT EDIT DIRECTLY */

#include "commands.h"

#include <string.h>
#include "ei.h"

#include "rts/ExternalAI/Interface/AISCommands.h"

#include "send_to.h"

int handle_command(int team_id, const struct SSkirmishAICallback* callback, ei_x_buff buff) {

    char command[64] = "";
    {
        int result = ei_decode_atom(buff.buff, &buff.index, command);
        if (result != 0) {
            fprintf(stderr, "[ERROR] cannot decode 'command' as 'char*', error code %i\n", result);
            ei_x_free(&buff);
            return result;
        }
    }
    if (strcmp(command, "COMMAND_CHEATS_GIVE_ME_NEW_UNIT") == 0) {
        int unitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitDefId = (int)tmp;
        }

        float pos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        int ret_newUnitId;
        struct SGiveMeNewUnitCheatCommand command = {
            unitDefId,
            pos_posF3,
            ret_newUnitId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_CHEATS_GIVE_ME_NEW_UNIT, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 3);
            ei_x_encode_atom(&sendbuff, "ok");
            ei_x_encode_atom(&sendbuff, "ret_newUnitId");
            ei_x_encode_long(&sendbuff, command.ret_newUnitId);
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_CHEATS_GIVE_ME_RESOURCE") == 0) {
        int resourceId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'resourceId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            resourceId = (int)tmp;
        }

        float amount;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'amount' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            amount = (float)tmp;
        }

        struct SGiveMeResourceCheatCommand command = {
            resourceId,
            amount,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_CHEATS_GIVE_ME_RESOURCE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_CHEATS_SET_MY_INCOME_MULTIPLIER") == 0) {
        float factor;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'factor' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            factor = (float)tmp;
        }

        struct SSetMyIncomeMultiplierCheatCommand command = {
            factor,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_CHEATS_SET_MY_INCOME_MULTIPLIER, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_GRAPH_LINE_ADD_POINT") == 0) {
        int lineId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'lineId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            lineId = (int)tmp;
        }

        float x;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'x' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            x = (float)tmp;
        }

        float y;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'y' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            y = (float)tmp;
        }

        struct SAddPointLineGraphDrawerDebugCommand command = {
            lineId,
            x,
            y,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_DEBUG_DRAWER_GRAPH_LINE_ADD_POINT, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_GRAPH_LINE_DELETE_POINTS") == 0) {
        int lineId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'lineId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            lineId = (int)tmp;
        }

        int numPoints;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'numPoints' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            numPoints = (int)tmp;
        }

        struct SDeletePointsLineGraphDrawerDebugCommand command = {
            lineId,
            numPoints,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_DEBUG_DRAWER_GRAPH_LINE_DELETE_POINTS, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_GRAPH_SET_POS") == 0) {
        float x;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'x' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            x = (float)tmp;
        }

        float y;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'y' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            y = (float)tmp;
        }

        struct SSetPositionGraphDrawerDebugCommand command = {
            x,
            y,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_DEBUG_DRAWER_GRAPH_SET_POS, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_GRAPH_SET_SIZE") == 0) {
        float w;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'w' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            w = (float)tmp;
        }

        float h;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'h' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            h = (float)tmp;
        }

        struct SSetSizeGraphDrawerDebugCommand command = {
            w,
            h,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_DEBUG_DRAWER_GRAPH_SET_SIZE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_DELETE") == 0) {
        int overlayTextureId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'overlayTextureId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            overlayTextureId = (int)tmp;
        }

        struct SDeleteOverlayTextureDrawerDebugCommand command = {
            overlayTextureId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_DELETE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_SET_POS") == 0) {
        int overlayTextureId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'overlayTextureId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            overlayTextureId = (int)tmp;
        }

        float x;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'x' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            x = (float)tmp;
        }

        float y;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'y' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            y = (float)tmp;
        }

        struct SSetPositionOverlayTextureDrawerDebugCommand command = {
            overlayTextureId,
            x,
            y,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_SET_POS, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_SET_SIZE") == 0) {
        int overlayTextureId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'overlayTextureId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            overlayTextureId = (int)tmp;
        }

        float w;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'w' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            w = (float)tmp;
        }

        float h;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'h' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            h = (float)tmp;
        }

        struct SSetSizeOverlayTextureDrawerDebugCommand command = {
            overlayTextureId,
            w,
            h,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_DEBUG_DRAWER_OVERLAYTEXTURE_SET_SIZE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DRAWER_FIGURE_DELETE") == 0) {
        int figureGroupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'figureGroupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            figureGroupId = (int)tmp;
        }

        struct SDeleteFigureDrawerCommand command = {
            figureGroupId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_DRAWER_FIGURE_DELETE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DRAWER_LINE_ADD") == 0) {
        float posFrom_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    posFrom_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        posFrom_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode posFrom_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float posTo_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    posTo_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        posTo_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode posTo_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        struct SAddLineDrawCommand command = {
            posFrom_posF3,
            posTo_posF3,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_DRAWER_LINE_ADD, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DRAWER_PATH_DRAW_ICON_AT_LAST_POS") == 0) {
        int cmdId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'cmdId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            cmdId = (int)tmp;
        }

        struct SDrawIconAtLastPosPathDrawerCommand command = {
            cmdId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_DRAWER_PATH_DRAW_ICON_AT_LAST_POS, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_DRAWER_POINT_REMOVE") == 0) {
        float pos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        struct SRemovePointDrawCommand command = {
            pos_posF3,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_DRAWER_POINT_REMOVE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_GROUP_CREATE") == 0) {
        int ret_groupId;
        struct SCreateGroupCommand command = {
            ret_groupId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_GROUP_CREATE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 3);
            ei_x_encode_atom(&sendbuff, "ok");
            ei_x_encode_atom(&sendbuff, "ret_groupId");
            ei_x_encode_long(&sendbuff, command.ret_groupId);
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_GROUP_ERASE") == 0) {
        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        struct SEraseGroupCommand command = {
            groupId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_GROUP_ERASE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_PATH_FREE") == 0) {
        int pathId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'pathId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            pathId = (int)tmp;
        }

        struct SFreePathCommand command = {
            pathId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_PATH_FREE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_PATH_INIT") == 0) {
        float start_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    start_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        start_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode start_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float end_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    end_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        end_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode end_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        int pathType;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'pathType' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            pathType = (int)tmp;
        }

        float goalRadius;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'goalRadius' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            goalRadius = (float)tmp;
        }

        int ret_pathId;
        struct SInitPathCommand command = {
            start_posF3,
            end_posF3,
            pathType,
            goalRadius,
            ret_pathId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_PATH_INIT, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 3);
            ei_x_encode_atom(&sendbuff, "ok");
            ei_x_encode_atom(&sendbuff, "ret_pathId");
            ei_x_encode_long(&sendbuff, command.ret_pathId);
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_SET_LAST_POS_MESSAGE") == 0) {
        float pos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        struct SSetLastPosMessageCommand command = {
            pos_posF3,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_SET_LAST_POS_MESSAGE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_TRACE_RAY") == 0) {
        float rayPos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    rayPos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        rayPos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode rayPos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float rayDir_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    rayDir_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        rayDir_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode rayDir_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        int srcUnitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'srcUnitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            srcUnitId = (int)tmp;
        }

        int ret_hitUnitId;
        int flags;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'flags' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            flags = (int)tmp;
        }

        struct STraceRayCommand command = {
            rayPos_posF3,
            rayDir_posF3,
            srcUnitId,
            ret_hitUnitId,
            flags,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_TRACE_RAY, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 3);
            ei_x_encode_atom(&sendbuff, "ok");
            ei_x_encode_atom(&sendbuff, "ret_hitUnitId");
            ei_x_encode_long(&sendbuff, command.ret_hitUnitId);
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_TRACE_RAY_FEATURE") == 0) {
        float rayPos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    rayPos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        rayPos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode rayPos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float rayDir_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    rayDir_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        rayDir_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode rayDir_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        int srcUnitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'srcUnitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            srcUnitId = (int)tmp;
        }

        int ret_hitFeatureId;
        int flags;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'flags' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            flags = (int)tmp;
        }

        struct SFeatureTraceRayCommand command = {
            rayPos_posF3,
            rayDir_posF3,
            srcUnitId,
            ret_hitFeatureId,
            flags,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_TRACE_RAY_FEATURE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 3);
            ei_x_encode_atom(&sendbuff, "ok");
            ei_x_encode_atom(&sendbuff, "ret_hitFeatureId");
            ei_x_encode_long(&sendbuff, command.ret_hitFeatureId);
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_AI_SELECT") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        struct SAiSelectUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_AI_SELECT, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_ATTACK") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int toAttackUnitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'toAttackUnitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            toAttackUnitId = (int)tmp;
        }

        struct SAttackUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toAttackUnitId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_ATTACK, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_ATTACK_AREA") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        float toAttackPos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    toAttackPos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        toAttackPos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode toAttackPos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float radius;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'radius' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            radius = (float)tmp;
        }

        struct SAttackAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toAttackPos_posF3,
            radius,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_ATTACK_AREA, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_BUILD") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int toBuildUnitDefId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'toBuildUnitDefId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            toBuildUnitDefId = (int)tmp;
        }

        float buildPos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    buildPos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        buildPos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode buildPos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        int facing;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'facing' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            facing = (int)tmp;
        }

        struct SBuildUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toBuildUnitDefId,
            buildPos_posF3,
            facing,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_BUILD, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_CAPTURE") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int toCaptureUnitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'toCaptureUnitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            toCaptureUnitId = (int)tmp;
        }

        struct SCaptureUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toCaptureUnitId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_CAPTURE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_CAPTURE_AREA") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        float pos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float radius;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'radius' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            radius = (float)tmp;
        }

        struct SCaptureAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
            radius,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_CAPTURE_AREA, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_CUSTOM") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int cmdId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'cmdId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            cmdId = (int)tmp;
        }

        float params[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    params[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        params[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode params as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        int params_size;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'params_size' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            params_size = (int)tmp;
        }

        struct SCustomUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            cmdId,
            params,
            params_size,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_CUSTOM, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_D_GUN") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int toAttackUnitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'toAttackUnitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            toAttackUnitId = (int)tmp;
        }

        struct SDGunUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toAttackUnitId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_D_GUN, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_D_GUN_POS") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        float pos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        struct SDGunPosUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_D_GUN_POS, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_FIGHT") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        float toPos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    toPos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        toPos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode toPos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        struct SFightUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toPos_posF3,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_FIGHT, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_GROUP_ADD") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int toGroupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'toGroupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            toGroupId = (int)tmp;
        }

        struct SGroupAddUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toGroupId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_GROUP_ADD, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_GROUP_CLEAR") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        struct SGroupClearUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_GROUP_CLEAR, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_GUARD") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int toGuardUnitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'toGuardUnitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            toGuardUnitId = (int)tmp;
        }

        struct SGuardUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toGuardUnitId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_GUARD, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_LOAD_ONTO") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int transporterUnitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'transporterUnitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            transporterUnitId = (int)tmp;
        }

        struct SLoadOntoUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            transporterUnitId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_LOAD_ONTO, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_LOAD_UNITS_AREA") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        float pos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float radius;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'radius' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            radius = (float)tmp;
        }

        struct SLoadUnitsAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
            radius,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_LOAD_UNITS_AREA, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_MOVE") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        float toPos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    toPos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        toPos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode toPos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        struct SMoveUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toPos_posF3,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_MOVE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_PATROL") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        float toPos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    toPos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        toPos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode toPos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        struct SPatrolUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toPos_posF3,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_PATROL, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_RECLAIM_AREA") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        float pos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float radius;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'radius' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            radius = (float)tmp;
        }

        struct SReclaimAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
            radius,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_RECLAIM_AREA, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_RECLAIM_FEATURE") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int toReclaimFeatureId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'toReclaimFeatureId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            toReclaimFeatureId = (int)tmp;
        }

        struct SReclaimFeatureUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toReclaimFeatureId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_RECLAIM_FEATURE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_RECLAIM_UNIT") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int toReclaimUnitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'toReclaimUnitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            toReclaimUnitId = (int)tmp;
        }

        struct SReclaimUnitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toReclaimUnitId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_RECLAIM_UNIT, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_REPAIR") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int toRepairUnitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'toRepairUnitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            toRepairUnitId = (int)tmp;
        }

        struct SRepairUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toRepairUnitId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_REPAIR, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_RESTORE_AREA") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        float pos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float radius;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'radius' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            radius = (float)tmp;
        }

        struct SRestoreAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
            radius,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_RESTORE_AREA, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_RESURRECT") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int toResurrectFeatureId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'toResurrectFeatureId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            toResurrectFeatureId = (int)tmp;
        }

        struct SResurrectUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toResurrectFeatureId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_RESURRECT, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_RESURRECT_AREA") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        float pos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    pos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        pos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode pos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float radius;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'radius' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            radius = (float)tmp;
        }

        struct SResurrectAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            pos_posF3,
            radius,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_RESURRECT_AREA, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SELF_DESTROY") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        struct SSelfDestroyUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_SELF_DESTROY, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SET_AUTO_REPAIR_LEVEL") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int autoRepairLevel;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'autoRepairLevel' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            autoRepairLevel = (int)tmp;
        }

        struct SSetAutoRepairLevelUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            autoRepairLevel,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_SET_AUTO_REPAIR_LEVEL, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SET_BASE") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        float basePos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    basePos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        basePos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode basePos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        struct SSetBaseUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            basePos_posF3,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_SET_BASE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SET_FIRE_STATE") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int fireState;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'fireState' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            fireState = (int)tmp;
        }

        struct SSetFireStateUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            fireState,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_SET_FIRE_STATE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SET_IDLE_MODE") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int idleMode;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'idleMode' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            idleMode = (int)tmp;
        }

        struct SSetIdleModeUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            idleMode,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_SET_IDLE_MODE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SET_MOVE_STATE") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int moveState;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'moveState' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            moveState = (int)tmp;
        }

        struct SSetMoveStateUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            moveState,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_SET_MOVE_STATE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SET_TRAJECTORY") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int trajectory;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'trajectory' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            trajectory = (int)tmp;
        }

        struct SSetTrajectoryUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            trajectory,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_SET_TRAJECTORY, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_SET_WANTED_MAX_SPEED") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        float wantedMaxSpeed;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'wantedMaxSpeed' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            wantedMaxSpeed = (float)tmp;
        }

        struct SSetWantedMaxSpeedUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            wantedMaxSpeed,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_SET_WANTED_MAX_SPEED, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_STOCKPILE") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        struct SStockpileUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_STOCKPILE, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_STOP") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        struct SStopUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_STOP, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_UNLOAD_UNIT") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        float toPos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    toPos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        toPos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode toPos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        int toUnloadUnitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'toUnloadUnitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            toUnloadUnitId = (int)tmp;
        }

        struct SUnloadUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toPos_posF3,
            toUnloadUnitId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_UNLOAD_UNIT, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_UNLOAD_UNITS_AREA") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        float toPos_posF3[3];
        {
            int arity = -1;
            {
                int result = ei_decode_tuple_header(buff.buff, &buff.index, &arity);
                if (result != 0) {
                    fprintf(stderr, "[ERROR] no tuple found for posf3 argument\n");
                    ei_x_free(&buff);
                    return result;
                }
                if (arity != 3) {
                    fprintf(stderr, "[ERROR] wrong arity %i for posf3 argument\n", arity);
                    ei_x_free(&buff);
                    return -1;
                }
            }
            int i = 0;
            for (; i < 3; i++) {
                double try1;
                int result = ei_decode_double(buff.buff, &buff.index, &try1);
                if (result == 0) {
                    toPos_posF3[i] = (float) try1;
                } else {
                    long try2;
                    result = ei_decode_long(buff.buff, &buff.index, &try2);
                    if (result == 0) {
                        toPos_posF3[i] = (float) try2;
                    } else {
                        fprintf(stderr, "[ERROR] cannot decode toPos_posF3 as posF3 on pos %i, error code %i\n", i, result);
                        ei_x_free(&buff);
                        return result;
                    }
                }
            }
        }
        float radius;
        {
            double tmp;
            int result = ei_decode_double(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'radius' as 'float', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            radius = (float)tmp;
        }

        struct SUnloadUnitsAreaUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toPos_posF3,
            radius,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_UNLOAD_UNITS_AREA, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_WAIT") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        struct SWaitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_WAIT, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_WAIT_DEATH") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int toDieUnitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'toDieUnitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            toDieUnitId = (int)tmp;
        }

        struct SDeathWaitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            toDieUnitId,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_WAIT_DEATH, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_WAIT_GATHER") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        struct SGatherWaitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_WAIT_GATHER, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_WAIT_SQUAD") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int numUnits;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'numUnits' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            numUnits = (int)tmp;
        }

        struct SSquadWaitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            numUnits,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_WAIT_SQUAD, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
    if (strcmp(command, "COMMAND_UNIT_WAIT_TIME") == 0) {
        int unitId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'unitId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            unitId = (int)tmp;
        }

        int groupId;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'groupId' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            groupId = (int)tmp;
        }

        short options;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'options' as 'short', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            options = (short)tmp;
        }

        int timeOut;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'timeOut' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            timeOut = (int)tmp;
        }

        int time;
        {
            long tmp;
            int result = ei_decode_long(buff.buff, &buff.index, &tmp);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'time' as 'int', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
            time = (int)tmp;
        }

        struct STimeWaitUnitCommand command = {
            unitId,
            groupId,
            options,
            timeOut,
            time,
        };
        erlang_pid from;
        {
            int result = ei_decode_pid(buff.buff, &buff.index, &from);
            if (result != 0) {
                fprintf(stderr, "[ERROR] cannot decode 'from' as 'erlang_pid', error code %i\n", result);
                ei_x_free(&buff);
                return result;
            }
        }

        ei_x_free(&buff);
        if (callback->Engine_handleCommand(team_id, COMMAND_TO_ID_ENGINE, -1, COMMAND_UNIT_WAIT_TIME, &command) < 0) {;
            fprintf(stderr, "cannot execute command!\n");
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "error");
            return send_to_pid(team_id, &from, sendbuff);
        } else {
            ei_x_buff sendbuff;
            ei_x_new_with_version(&sendbuff);
            ei_x_encode_tuple_header(&sendbuff, 1);
            ei_x_encode_atom(&sendbuff, "ok");
            return send_to_pid(team_id, &from, sendbuff);
        }
    }
}