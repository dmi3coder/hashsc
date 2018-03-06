//
// Created by dmi3coder on 2/16/18.
//

#include <iostream>
#include <glog/logging.h>
#include "stripper.h"
#include "../command/command.h"

stripper::stripper(const int *argc, char **argv) {
    this->arguments = new std::vector<std::string>(argv + 1, argv + *argc);
    this->flags = new std::vector<std::string>();
    this->inputs = new std::vector<std::string>();
}

void stripper::strip() {
    this->stripFlags();
    this->stripCommand();
    this->stripInputs();
}

void stripper::stripFlags() {
    if(arguments == nullptr){
        return;
    }
    auto iterator = arguments->begin();
    while (iterator != arguments->end()) {
        std::string flagCandidate = *iterator;
        if (flagCandidate.find("--") != std::string::npos) {
            flags->push_back(flagCandidate);
            iterator = arguments->erase(iterator);
            DLOG(INFO) << "new flag: " << flagCandidate << std::endl;
        } else {
            ++iterator;
        }
    }
}

void stripper::stripCommand() {
    if(arguments == nullptr || arguments->empty()){
        cmd = new std::string(command::CMD_CONVERT_STREAM);
    } else if(arguments->size() == 1){
        cmd = new std::string(command::CMD_ENCODE);
    } else if(arguments->size() == 2) {
        cmd = new std::string(arguments->at(0));
        arguments->erase(arguments->begin());
    }
    DLOG(INFO) << *cmd << std::endl;
}

void stripper::stripInputs() {
    this->inputs = this->arguments;
}
