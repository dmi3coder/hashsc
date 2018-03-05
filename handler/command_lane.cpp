//
// Created by dmi3coder on 2/16/18.
//

#include "command_lane.h"
#include "../command/stream_command.h"

void command_lane::start() {
    auto *context = new command_context(current_stripper, this);

    for (auto &command : *commands) {
        command.second->context = context;
        if(auto * io_command = dynamic_cast<stream_command*>(command.second)){
            io_command->input = inputStream;
            io_command->output = outputStream;
        }
        std::cout << "command execution.." << std::endl;
        command.second->Execute();
    }
}

