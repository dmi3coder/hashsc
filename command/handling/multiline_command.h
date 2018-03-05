//
// Created by dmi3coder on 3/5/18.
//

#ifndef HASHSC_MULTILINE_COMMAND_H
#define HASHSC_MULTILINE_COMMAND_H


#include "../stream_command.h"

class multiline_command : stream_command {
public:
    int Execute() override;
};


#endif //HASHSC_MULTILINE_COMMAND_H
