#include "CommandHelp.hpp"

CommandHelp::CommandHelp() 
    : ICommand("help")
{
}

void CommandHelp::runCommand(JsonCheck& userFile) {
    assert(commArgs.empty());
    userFile.help();
}
