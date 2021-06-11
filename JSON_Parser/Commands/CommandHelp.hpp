#ifndef HELP_H
#define HELP_H

#include "ICommand.hpp"

class CommandHelp : public ICommand {
public:
    CommandHelp();
    
    void runCommand(JsonCheck& userFile);
};

#endif
