#ifndef SET_H
#define SET_H

#include "ICommand.hpp"

class CommandSet : public ICommand {
public:
    CommandSet();
    
    void runCommand(JsonCheck& userFile);
};

#endif
