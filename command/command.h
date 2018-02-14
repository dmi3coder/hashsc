#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>


class command
{
protected:
    std::istream *input;
    std::ostream *output;
public:
    command(std::istream* inputStream, std::ostream* outputStream);
    virtual int Execute() = 0;
};

#endif // COMMAND_H
