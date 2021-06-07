#ifndef SAVE_AS_H
#define SAVE_AS_H

#include "ICommand.hpp"

class CommandSaveAs : public ICommand {
private:
    CommandSaveAs();
    
    void executeCmmd(JsonCheck& userFile);
};

#endif
