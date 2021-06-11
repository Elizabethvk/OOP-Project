#ifndef CLOSE_H
#define CLOSE_H

#include "ICommand.hpp"

class CommandClose : public ICommand {
public:
    CommandClose();
    
    void runCommand(JsonCheck& userFile);
};

#endif
