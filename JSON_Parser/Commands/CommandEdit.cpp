#include "CommandEdit.hpp"

CommandEdit::CommandEdit() 
    : ICommand("edit")
{
}

void CommandEdit::runCommand(JsonCheck& userFile) {
    stringstream userArguments;
    assert(commArgs.empty());

    for (unsigned int i = 0; i < commArgs.size(); ++i) {
        userArguments << commArgs[i];
    }

    userFile.edit(commArgs[0], userArguments);
}