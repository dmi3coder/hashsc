#ifndef BASE64_ENCODER_COMMAND_H
#define BASE64_ENCODER_COMMAND_H

#include "../stream_command.h"
#include <string>

class base64_encoder_command : public stream_command
{
protected:
public:
    base64_encoder_command(std::istream &inputStream, std::ostream &outputStream);
    int Execute() override;
};

#endif // BASE64_ENCODER_COMMAND_H
