#include "CommandValidate.hpp" 

CommandValidate::CommandValidate()
    : ICommand("validate")
{
}

void CommandValidate::runCommand(JsonCheck& userFile) {
    assert(commArgs.empty());

    userFile.checkJsonFile();
}