#ifndef SAVE_H
#define SAVE_H

#include "ICommand.hpp"

class CommandSave : public ICommand {
public:
    CommandSave();
    
    void runCommand(JsonCheck& userFile);
};

#endif

