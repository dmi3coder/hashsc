//
// Created by dmi3coder on 2/16/18.
//

#include "command_lane.h"
#include "../command/stream_command.h"

void command_lane::start() {
    for (auto &command : commands) {
        if(auto * io_command = dynamic_cast<stream_command*>(command)){
            io_command->input = inputStream;
            io_command->output = outputStream;
        }
        command->Execute();
    }
}
