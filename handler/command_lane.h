//
// Created by dmi3coder on 2/16/18.
//

#ifndef HASHSC_COMMAND_FLOW_H
#define HASHSC_COMMAND_FLOW_H

#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include "../command/command.h"

class command;

class command_lane {
public:
    void start();
    std::map<const std::string, command*> *commands;
    std::istream *inputStream;
    std::ostream *outputStream;
    stripper *current_stripper;

};


#endif //HASHSC_COMMAND_FLOW_H
