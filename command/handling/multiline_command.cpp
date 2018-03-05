//
// Created by dmi3coder on 3/5/18.
//

#include "multiline_command.h"
#include "../hashing/base64_encoder_command.h"
#include "map"
#include "../command.h"
#include "istream"
#include <sstream>
#include <string>
#include <iostream>
#include <stdexcept>

std::string insertLines(std::istringstream *is) {
    char c;
    std::ostringstream os = {};
    enum { CHARACTER, ESCAPE } state = CHARACTER;

    while (is->get(c)) {
        switch (state) {
            case CHARACTER:
                if (c == '\\') {
                    state = ESCAPE;
                } else {
                    os << c;
                }
                break;

            case ESCAPE:
                switch (c) {
                    case 'n': os << '\n'; break;
                    case 't': os << '\t'; break;
                }
                state = CHARACTER;
                break;
        }
    }
    return os.str();
}


int multiline_command::Execute() {
    auto *is = new std::istringstream();
    is->str(*new std::string(std::istreambuf_iterator<char>(*input), {}));
    std::string fixedString = insertLines(is);
    is->str(fixedString);
    std::string nextArgument;
    std::cout << "Fixed string: " << fixedString << std::endl;
    while (std::getline(*is, nextArgument, '\n')) {
        std::cout << "LINE: " << nextArgument << std::endl;
        auto *lineEncodeCommand = new base64_encoder_command();
        auto *lineStream = new std::istringstream(nextArgument);
        lineEncodeCommand->input = lineStream;
        this->context->lane->commands->insert(std::pair<std::string, command*>(command::CMD_ENCODE, lineEncodeCommand));
    }

    return 9;
}
