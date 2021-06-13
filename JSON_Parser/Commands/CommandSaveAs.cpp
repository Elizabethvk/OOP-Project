#include "CommandSaveAs.hpp"


CommandSaveAs::CommandSaveAs() 
    : ICommand("saveas")
{
}

void CommandSaveAs::runCommand(JsonCheck& userFile) {
    assert(commArgs.size() == 1);
    
    userFile.saveAsFile(commArgs[0]);
}