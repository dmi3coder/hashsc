//
// Created by dmi3coder on 2/16/18.
//

#ifndef HASHSC_STRIPPER_H
#define HASHSC_STRIPPER_H

#include <vector>
#include <string>

class stripper {
public:
    stripper(int *argc, char **argv);

    void strip();

private:
    int *argc;
    std::string *cmd = nullptr;
    std::vector<std::string> *flags;
    char **argv;

    void stripFlags();
    void stripCommand();
};


#endif //HASHSC_STRIPPER_H
