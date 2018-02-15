#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>


class command
{
public:
    virtual int Execute() = 0;
};

#endif // COMMAND_H
