#ifndef MOVE_H
#define MOVE_H

#include "ICommand.hpp"

class CommandMove : public ICommand {
public:
    CommandMove();
    
    void runCommand(JsonCheck& userFile);
};

#endif