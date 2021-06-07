#ifndef MOVE_H
#define MOVE_H

#include "ICommand.hpp"

class CommandMove : public ICommand {
private:
    CommandMove();
    
    void executeCmmd(JsonCheck& userFile);
};

#endif