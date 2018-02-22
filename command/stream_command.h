//
// Created by dmi3coder on 2/15/18.
//

#ifndef HASHSC_STREAM_COMMAND_H
#define HASHSC_STREAM_COMMAND_H


#include "command.h"

class stream_command: public command {
public:
    std::istream *input;
    std::ostream *output;
};


#endif //HASHSC_STREAM_COMMAND_H
