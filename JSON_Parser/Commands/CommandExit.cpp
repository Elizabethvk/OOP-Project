#include "CommandExit.hpp"


CommandExit::CommandExit() 
    : ICommand("exit")
{
}


void CommandExit::runCommand(JsonCheck& userFile) {
    //assert(commArgs.empty());
    userFile.terminateFunction();
}