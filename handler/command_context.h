//
// Created by dmi3coder on 2/22/18.
//

#ifndef HASHSC_COMMAND_CONTEXT_H
#define HASHSC_COMMAND_CONTEXT_H


#include "../stripper/stripper.h"
#include "command_lane.h"

class command_context {
public:
    command_context(stripper*,command_lane*);
    stripper *commandStripper;
    command_lane *lane;
};


#endif //HASHSC_COMMAND_CONTEXT_H
