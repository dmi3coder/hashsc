//
// Created by dmi3coder on 2/16/18.
//

#include <glog/logging.h>
#include "command_lane.h"
#include "../command/stream_command.h"
using namespace std;
void command_lane::start() {
    auto *context = new command_context(current_stripper, this);
    vector<command*> commandList = {};
    auto iter = commands->begin();

    while (iter != commands->end()) {
        DLOG(INFO) << "commands:" << commands->size() << endl;

        (*iter).second->context = context;
        if(auto * io_command = dynamic_cast<stream_command*>((*iter).second)){
            if(io_command->input == nullptr) io_command->input = inputStream;
            if(io_command->output == nullptr) io_command->output = outputStream;
        }
        DLOG(INFO) << "command execution.." << std::endl;
        int result = (*iter).second->Execute();
        if(result == 9) {
            iter = commands->begin();
            commands->erase(iter);
        }
        iter++;
    }

}

