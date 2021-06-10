#ifndef VALIDATE_H
#define VALIDATE_H

#include "ICommand.hpp"

class CommandValidate : public ICommand {
private:
    CommandValidate();
    
    void executeCmmd(JsonCheck& userFile);
};

#endif
