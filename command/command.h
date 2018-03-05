#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <string>
#include "../handler/command_context.h"

class command_context;

class command
{
public:
    virtual int Execute() = 0;
    static const std::string CMD_CONVERT_STREAM;
    static const std::string CMD_ENCODE;
    command_context *context = nullptr;
};

#endif // COMMAND_H
