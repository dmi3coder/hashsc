//
// Created by dmi3coder on 2/16/18.
//

#ifndef HASHSC_COMMAND_FLOW_H
#define HASHSC_COMMAND_FLOW_H

#include <vector>
#include <string>
#include "../command/command.h"

class command_lane {
public:
    void start();
    std::vector<command*> commands;
    std::istream *inputStream;
    std::ostream *outputStream;

};


#endif //HASHSC_COMMAND_FLOW_H
