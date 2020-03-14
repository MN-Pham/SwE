#include <iostream>
#include "Motor.h"
#include "Command.h"

void CommandProcessor::addCommand (const std::string &command,
                                   CommandProcessor::commandfunction_t cf) {
    commands_.insert({command, cf});
}

void CommandProcessor::executeCommand (const std::string &command) {
    //p is an iterator
    auto p = commands_.find(command);
    if (p != end(commands_)) {
        auto commandfunc = (*p).second;
        commandfunc();
    }
    else {
        std::cerr<<"Command not found."<<std::endl;
    }
}