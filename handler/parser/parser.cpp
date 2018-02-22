//
// Created by dmi3coder on 2/16/18.
//

#include "parser.h"

std::vector<command *> *parser::parse(stripper *stripper) {
    auto *vector = new std::vector<command *>();
    for(auto argument : *stripper->arguments){
        if(argument == "--ml"){

        }

    }
    return vector;
}
