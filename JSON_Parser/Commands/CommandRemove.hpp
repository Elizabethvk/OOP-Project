#ifndef REMOVE_H
#define REMOVE_H

#include "ICommand.hpp"

class CommandRemove : public ICommand {
public:
    CommandRemove();
    
    void runCommand(JsonCheck& userFile);
};

#endif