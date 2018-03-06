//
// Created by dmi3coder on 3/5/18.
//

#include "multiline_command.h"
#include "../hashing/base64_encoder_command.h"
#include <sstream>
#include <glog/logging.h>

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
    auto *normalizedInputStream = new std::istringstream();
    normalizedInputStream->str(fixedString);
    std::string nextArgument;
    DLOG(INFO) << "Fixed string: " << fixedString << std::endl;
    auto *multiLineCommands = new std::vector<stream_command*>;
    while (std::getline(*normalizedInputStream, nextArgument, '\n')) {
        DLOG(INFO) << "LINE: " << nextArgument << std::endl;
        auto *lineEncodeCommand = new base64_encoder_command();
        auto *lineStream = new std::istringstream(nextArgument);
        lineEncodeCommand->input = lineStream;
        multiLineCommands->push_back(lineEncodeCommand);
    }

    for(auto cmd : *multiLineCommands) {
        cmd->output = output;
        cmd->context = context;
        cmd->Execute();
    }

    return 0;
}
