#ifndef CREATE_H
#define CREATE_H

#include "ICommand.hpp"

class CommandCreate : public ICommand {
public:
    CommandCreate();
    
    void runCommand(JsonCheck& userFile);
};

#endif