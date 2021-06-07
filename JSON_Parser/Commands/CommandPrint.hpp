#ifndef PRINT_H
#define PRINT_H

#include "ICommand.hpp"

class CommandPrint : public ICommand {
private:
    CommandPrint();
    
    void executeCmmd(JsonCheck& userFile);
};

#endif
