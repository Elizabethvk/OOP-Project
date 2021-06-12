#ifndef EXIT_H
#define EXIT_H

#include "ICommand.hpp"

class CommandExit : public ICommand {
public:
    CommandExit();
    
    void runCommand(JsonCheck& userFile);
};



#endif