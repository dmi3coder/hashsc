#include "base64_encoder_command.h"
#include <sstream>
#include "base64.h"


int base64_encoder_command::Execute() {
    std::string *data = new std::string(std::istreambuf_iterator<char>(*input), {});
    *output << base64_encode(reinterpret_cast<const unsigned char*>(data->c_str()), data->length()) << std::endl;
    delete data;
    return 0;
}

