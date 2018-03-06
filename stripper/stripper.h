//
// Created by dmi3coder on 2/16/18.
//

#ifndef HASHSC_STRIPPER_H
#define HASHSC_STRIPPER_H

#include <vector>
#include <string>

class stripper {
public:

    stripper(const int *argc, char **argv);

    void strip();
    std::vector<std::string> *arguments = nullptr;
    std::string *cmd = nullptr;
    std::vector<std::string> *flags = nullptr;
    std::vector<std::string> *inputs = nullptr;
    void stripFlags();
    void stripCommand();
    void stripInputs();
};


#endif //HASHSC_STRIPPER_H
