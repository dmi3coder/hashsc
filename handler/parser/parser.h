//
// Created by dmi3coder on 2/16/18.
//

#ifndef HASHSC_PARSER_H
#define HASHSC_PARSER_H


#include <vector>
#include "../../command/command.h"
#include "../../stripper/stripper.h"
#include <map>
#include <unordered_map>

class parser {
public:
    std::map<const std::string, command *> * parse(stripper *stripper);

};


#endif //HASHSC_PARSER_H
