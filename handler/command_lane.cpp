//
// Created by dmi3coder on 2/16/18.
//

#include "command_lane.h"
#include "../command/stream_command.h"
using namespace std;
void command_lane::start() {
    auto *context = new command_context(current_stripper, this);

    auto iter = commands->begin();

    while (iter != commands->end()) {
        cout << "commands:" << commands->size() << endl;

        (*iter).second->context = context;
        if(auto * io_command = dynamic_cast<stream_command*>((*iter).second)){
            io_command->input = inputStream;
            io_command->output = outputStream;
        }
        std::cout << "command execution.." << std::endl;
        int result = (*iter).second->Execute();
        if(result == 9) {
            std::cout << "reverse" << std::endl;
            iter = commands->begin();
        } else {
            iter++;
        }
    }

}

