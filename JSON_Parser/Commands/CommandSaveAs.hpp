#ifndef SAVE_AS_H
#define SAVE_AS_H

#include "ICommand.hpp"

class CommandSaveAs : public ICommand {
public:
    CommandSaveAs();
    
    void runCommand(JsonCheck& userFile);
};

#endif
