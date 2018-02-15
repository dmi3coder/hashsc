//
// Created by dmi3coder on 2/15/18.
//

#ifndef HASHSC_STREAM_COMMAND_H
#define HASHSC_STREAM_COMMAND_H


#include "command.h"

class stream_command: public command {
protected:
    std::istream *input;
    std::ostream *output;
public:
    stream_command(std::istream &inputStream, std::ostream &outputStream);

};


#endif //HASHSC_STREAM_COMMAND_H
