#ifndef VALIDATE_H
#define VALIDATE_H

#include "ICommand.hpp"

class CommandValidate : public ICommand {
public:
    CommandValidate();
    
    void runCommand(JsonCheck& userFile);
};

#endif
