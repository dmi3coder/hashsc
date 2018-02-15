#ifndef BASE64_ENCODER_COMMAND_H
#define BASE64_ENCODER_COMMAND_H

#include "../command.h"
#include <string>

class base64_encoder_command : public command
{
protected:
public:
    base64_encoder_command(std::istream &inputStream, std::ostream &outputStream);
    int Execute();
};

#endif // BASE64_ENCODER_COMMAND_H
