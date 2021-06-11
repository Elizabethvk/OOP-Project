#ifndef FILE_OPEN_H
#define FILE_OPEN_H

#include "ICommand.hpp"

class CommandFileOpen : public ICommand {
public:
    CommandFileOpen();
    
    void runCommand(JsonCheck& userFile);
};

#endif
