#ifndef DELETE_H
#define DELETE_H

#include "ICommand.hpp"

class CommandDelete : public ICommand {
public:
    CommandDelete();
    
    void runCommand(JsonCheck& userFile);
};

#endif