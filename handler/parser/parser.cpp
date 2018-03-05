//
// Created by dmi3coder on 2/16/18.
//

#include "parser.h"
#include "../../command/hashing/base64_encoder_command.h"

using namespace std;

std::map<const std::string, command *> *parser::parse(stripper *stripper) {
    auto commandMap = new std::map<const std::string, command*>();
    if(*(stripper->cmd) == command::CMD_ENCODE) {
        commandMap->insert(std::pair<std::string, command*>(command::CMD_ENCODE, new base64_encoder_command()));
    }
    for(const auto &argument : *stripper->flags){
        if(argument == "--encode"){
            commandMap->insert(std::pair<std::string, command*>(command::CMD_ENCODE, new base64_encoder_command()));
        }
    }
    std::cout << "Size: " << commandMap->size() << std::endl;

    return commandMap;
}
