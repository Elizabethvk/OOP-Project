#ifndef 
#define 

#include "ICommand.hpp"

class Command : public ICommand {
private:
    Command();
    
    void executeCmmd(JsonCheck& userFile);
};

#endif
