#include <iostream>
#include "base64.h"
#include <string> 

int main(int argc, char* argv[]) {
    std::string encodeText = argv[1];
    std::cout << base64_encode(reinterpret_cast<const unsigned char*>(encodeText.c_str()), encodeText.length()) << std::endl;
    return 0;
}
