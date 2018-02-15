#include <iostream>
#include "./command/hashing/base64.h"
#include <string>
#include "yaml-cpp/yaml.h"
#include <fstream>
#include <sstream>
#include "command/hashing/base64_encoder_command.h"

using namespace std;

bool isValid(YAML::Node& config);

int handleCommand(int argc, char* argv[]) {
    cout << argv[1] << endl;
    string argument = argv[1];
    if(argument == "--append") {
        std::cout << "parsing..." << std::endl;
        YAML::Node config = YAML::LoadFile(argv[2]);
        cout << config["apiVersion"].as<string>() << endl;
        if(isValid(config)) {
            YAML::Node data = config["data"];
            string encodeText = argv[4];
            data[argv[3]] = base64_encode(reinterpret_cast<const unsigned char*>(encodeText.c_str()), encodeText.length());
            string filepath = argv[2];
            std::ofstream fout(filepath);
            fout << config;
            cout << "OK" << endl;
        } else {
            cout << "Sorry, something wrong with this file" << endl;
        }
    }
}

bool isValid(YAML::Node &config) {
    return config["kind"].as<string>() == "Secret";
}

int main(int argc, char* argv[]) {
    std::cout << "Handling "<< argc <<" arguments" << std::endl;
    switch (argc) {
    case 1:{
        for(string line; std::getline(std::cin, line);) {
            auto *ist = new istringstream(line);
            base64_encoder_command command(*ist, cout);
            command.Execute();
            delete ist;
        }
    } break;
    case 2:{
        auto *ist = new istringstream(argv[1]);
        base64_encoder_command command(*ist, cout);
        command.Execute();
        delete ist;
    }
        break;
    case 5:{
        return handleCommand(argc, argv);
    }
        break;
    default:
        break;
    }
    return 0;
}
