//
// Created by dmi3coder on 3/5/18.
//

#include "multiline_command.h"
#include "../hashing/base64_encoder_command.h"
#include "map"
#include "../command.h"


int multiline_command::Execute() {
    std::string nextArgument;
    while (std::getline(*input, nextArgument, '\n')) {
        this->context->lane->commands->insert(std::pair<std::string, command*>(command::CMD_ENCODE, new base64_encoder_command()));
    }

    return 0;
}
