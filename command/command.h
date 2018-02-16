#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <string>

class command
{
public:
    virtual int Execute() = 0;
    static const std::string CMD_CONVERT_STREAM;
    static const std::string CMD_ENCODE;
};

#endif // COMMAND_H
