#include "CommandEdit.hpp"

CommandEdit::CommandEdit() 
    : ICommand("edit")
{
}

void CommandEdit::runCommand(JsonCheck& userFile) {
    stringstream userArguments;
    assert(!commArgs.empty());

    //TODO Array <= ?
    for (unsigned int i = 0; i < commArgs.size(); ++i) {

        userArguments << commArgs[i];
        if (i < commArgs.size() - 1) {
            userArguments << " ";
        }
    }

    userFile.edit(commArgs[0], userArguments);
}