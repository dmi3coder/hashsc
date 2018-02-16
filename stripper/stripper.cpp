//
// Created by dmi3coder on 2/16/18.
//

#include <iostream>
#include "stripper.h"

stripper::stripper(int *argc, char **argv) {
    this->argc = argc;
    this->argv = argv;
    this->flags = new std::vector<std::string>();
}

void stripper::strip() {
    this->stripFlags();
    this->stripCommand();
}

void stripper::stripFlags() {
    for (int i = 0; i < *argc; ++i) {
        std::string flagCandidate = argv[i];
        if(flagCandidate.find("--") != std::string::npos) {
            flags->push_back(flagCandidate);
            std::cout << flagCandidate;
        }
    }
}

void stripper::stripCommand() {

}
