#ifndef SET_H
#define SET_H

#include "ICommand.hpp"

class CommandSet : public ICommand {
private:
    CommandSet();
    
    void executeCmmd(JsonCheck& userFile);
};

#endif
