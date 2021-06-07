#ifndef SAVE_H
#define SAVE_H

#include "ICommand.hpp"

class CommandSave : public ICommand {
private:
    CommandSave();
    
    void executeCmmd(JsonCheck& userFile);
};

#endif

