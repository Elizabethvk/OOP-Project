#ifndef DELETE_H
#define DELETE_H

#include "ICommand.hpp"

class CommandRemove : public ICommand {
public:
    CommandRemove();
    
    void runCommand(JsonCheck& userFile);
};

#endif