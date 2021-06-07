#ifndef CREATE_H
#define CREATE_H

#include "ICommand.hpp"

class CommandCreate : public ICommand {
private:
    CommandCreate();
    
    void executeCmmd(JsonCheck& userFile);
};

#endif