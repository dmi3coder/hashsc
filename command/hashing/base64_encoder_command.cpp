#include "base64_encoder_command.h"
#include <string>
#include <iostream>
#include <sstream>
#include "base64.h"

base64_encoder_command::base64_encoder_command(std::istream &inputStream, std::ostream &outputStream): command::command(inputStream, outputStream){}

int base64_encoder_command::Execute() {
    std::string *data = new std::string(std::istreambuf_iterator<char>(*input), {});
    *output << base64_encode(reinterpret_cast<const unsigned char*>(data->c_str()), data->length()) << std::endl;
    return 0;
}
