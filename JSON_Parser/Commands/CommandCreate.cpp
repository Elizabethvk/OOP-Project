#include "CommandCreate.hpp"



CommandCreate::CommandCreate() 
    : ICommand("create")
{
}


void CommandCreate::runCommand(JsonCheck& userFile) {
    assert(!commArgs.empty());
    stringstream userCommandArgs;

    for (unsigned int i = 0; i < commArgs.size(); ++i) {
        userCommandArgs << commArgs[i];
    }

    userFile.create(commArgs[0], userCommandArgs);
}