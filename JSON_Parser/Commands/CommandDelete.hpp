#ifndef DELETE_H
#define DELETE_H

#include "ICommand.hpp"

class CommandDelete : public ICommand {
private:
    CommandDelete();
    
    void executeCmmd(JsonCheck& userFile);
};

#endif