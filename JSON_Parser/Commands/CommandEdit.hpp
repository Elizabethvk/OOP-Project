#ifndef SET_H
#define SET_H

#include "ICommand.hpp"

class CommandEdit : public ICommand {
public:
    CommandEdit();
    
    void runCommand(JsonCheck& userFile);
};

#endif
