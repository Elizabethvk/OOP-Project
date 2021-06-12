#include "CommandRemove.hpp"

CommandRemove::CommandRemove() 
    : ICommand("remove")
{
}
    
void CommandRemove::runCommand(JsonCheck& userFile) {
    assert(commArgs.size() == 1);

    userFile.removeByPath(commArgs[0]);
}