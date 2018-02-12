#include <iostream>
#include "base64.h"
#include <string>
#include "yaml-cpp/yaml.h"

using namespace std;
int handleCommand(int argc, char* argv[]) {
    cout << argv[1] << endl;
    string argument = argv[1];
    if(argument == "--append") {
        std::cout << "parsing..." << std::endl;
        YAML::Node config = YAML::LoadFile(argv[2]);
        cout << config["apiVersion"].as<string>() << endl;
    }
}

int main(int argc, char* argv[]) {
    std::cout << "Handling "<< argc <<" arguments" << std::endl;
    switch (argc) {
    case 2:{
        std::string encodeText = argv[1];
        std::cout << base64_encode(reinterpret_cast<const unsigned char*>(encodeText.c_str()), encodeText.length()) << std::endl;
    }
        break;
    case 3:{
        return handleCommand(argc, argv);
    }
        break;
    default:
        break;
    }
    return 0;
}
