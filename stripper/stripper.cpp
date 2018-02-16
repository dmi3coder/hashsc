//
// Created by dmi3coder on 2/16/18.
//

#include <iostream>
#include "stripper.h"
#include "../command/command.h"

stripper::stripper(const int *argc, char **argv) {
    this->arguments = new std::vector<std::string>(argv + 1, argv + *argc);
    this->flags = new std::vector<std::string>();
}

void stripper::strip() {
    this->stripFlags();
    this->stripCommand();
}

void stripper::stripFlags() {
    auto iterator = arguments->begin();
    while (iterator != arguments->end()) {
        std::string flagCandidate = *iterator;
        if (flagCandidate.find("--") != std::string::npos) {
            flags->push_back(flagCandidate);
            iterator = arguments->erase(iterator);
            std::cout << flagCandidate << std::endl;
        } else {
            ++iterator;
        }
    }
}

void stripper::stripCommand() {
    if(arguments->size() == 1){
        cmd = new std::string(command::CMD_CONVERT_STREAM);
    } else if(arguments->size() == 2){
        cmd = new std::string(command::CMD_ENCODE);
    } else if(arguments->size() == 3) {
        cmd = new std::string(arguments->at(1));
    }
    arguments->erase(arguments->begin());
    std::cout << *cmd << std::endl;
}
