#include "CommandClose.hpp"



CommandClose::CommandClose() 
    : ICommand("close")
{
}


void CommandClose::runCommand(JsonCheck& userFile) {
    
   // assert(commArgs.empty());
    
    userFile.closeFile();
}