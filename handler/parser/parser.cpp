//
// Created by dmi3coder on 2/16/18.
//

#include <glog/logging.h>
#include "parser.h"
#include "../../command/hashing/base64_encoder_command.h"
#include "../../command/handling/multiline_command.h"

using namespace std;

std::map<const std::string, command *> *parser::parse(stripper *stripper) {
    auto commandMap = new std::map<const std::string, command*>();
    if(*(stripper->cmd) == command::CMD_ENCODE) {
        commandMap->insert(std::pair<std::string, command*>(command::CMD_ENCODE, new base64_encoder_command()));
    } else if (*(stripper->cmd) == command::CMD_CONVERT_STREAM) {
        commandMap->insert(
                std::pair<std::string, command *>(command::CMD_CONVERT_STREAM, new base64_encoder_command()));
    }
    for(const auto &argument : *stripper->flags){
        if(argument == "--encode"){
            commandMap->insert(std::pair<std::string, command*>(command::CMD_ENCODE, new base64_encoder_command()));
        } else if(argument == "--ml"){
            commandMap->insert(std::pair<std::string, command*>(command::CMD_MULTILINE_ENCODE, new multiline_command()));
            commandMap->erase(command::CMD_ENCODE);
        }
    }
    DLOG(INFO) << "Parser commands size: " << commandMap->size() << std::endl;

    return commandMap;
}
