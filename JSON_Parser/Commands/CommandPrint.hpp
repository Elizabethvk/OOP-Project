#ifndef PRINT_H
#define PRINT_H

#include "ICommand.hpp"

class CommandPrint : public ICommand {
public:
    CommandPrint();
    
    void runCommand(JsonCheck& userFile);
};

#endif
