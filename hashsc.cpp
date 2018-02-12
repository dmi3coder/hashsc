#include <iostream>
#include "base64.h"
#include <string>
#include "yaml-cpp/yaml.h"
#include <fstream>

int main(int argc, char* argv[]) {
    YAML::Node config = YAML::LoadFile("config.yaml");
    switch (argc) {
    case 2:{
        std::string encodeText = argv[1];
        std::cout << base64_encode(reinterpret_cast<const unsigned char*>(encodeText.c_str()), encodeText.length()) << std::endl;
    }
        break;
    case 3:{
    }
        break;
    default:
        break;
    }
    return 0;
}
