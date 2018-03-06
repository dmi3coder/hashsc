#include <iostream>
#include "./command/hashing/base64.h"
#include <string>
#include "yaml-cpp/yaml.h"
#include <fstream>
#include <sstream>
#include "command/hashing/base64_encoder_command.h"
#include "stripper/stripper.h"
#include "handler/parser/parser.h"
#include "handler/command_lane.h"
#include <glog/logging.h>

using namespace std;

bool isValid(YAML::Node& config);

int handleCommand(int argc, char* argv[]) {
    cout << argv[1] << endl;
    string argument = argv[1];
    if(argument == "--append") {
        LOG(INFO) << "parsing..." << std::endl;
        YAML::Node config = YAML::LoadFile(argv[2]);
        LOG(INFO) << config["apiVersion"].as<string>() << endl;
        if(isValid(config)) {
            YAML::Node data = config["data"];
            string encodeText = argv[4];
            data[argv[3]] = base64_encode(reinterpret_cast<const unsigned char*>(encodeText.c_str()), encodeText.length());
            string filepath = argv[2];
            std::ofstream fout(filepath);
            fout << config;
            LOG(INFO) << "OK" << endl;
        } else {
            cout << "Sorry, something wrong with this file" << endl;
        }
    }
}

bool isValid(YAML::Node &config) {
    return config["kind"].as<string>() == "Secret";
}

int main(int argc, char* argv[]) {
    FLAGS_alsologtostderr = true;
    google::InitGoogleLogging(argv[0]);
    auto *main_stripper = new stripper(&argc, argv);
    main_stripper->strip();
    auto *cmd_parser = new parser();
    auto *lane = new command_lane();
    DLOG(INFO) << "Stripper arguments size:" << main_stripper->arguments->size() << endl;
    lane->commands = cmd_parser->parse(main_stripper);
    lane->outputStream = &std::cout;
    lane->current_stripper = main_stripper;
    if((main_stripper->inputs->empty())){
        DLOG(INFO) << "Inputs is empty, using \u001B[33mcin\u001B[0m instead.." << endl;
        lane->inputStream = &cin;
    } else {
        auto *ist = new istringstream(main_stripper->inputs->at(0));
        lane->inputStream = ist;
    }
    lane->start();
    return 0;
}
