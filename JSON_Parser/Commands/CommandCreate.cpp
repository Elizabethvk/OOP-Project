#include "CommandCreate.hpp"



CommandCreate::CommandCreate() 
    : ICommand("create")
{
}


void CommandCreate::runCommand(JsonCheck& userFile) {
    if (commArgs.empty()) {
        cout << "No parameters found." << endl;
        return;
    }
   // assert(!commArgs.empty());
    stringstream userCommandArgs;

    for (unsigned int i = 0; i < commArgs.size(); ++i) {
        userCommandArgs << commArgs[i];
        if (i < commArgs.size() - 1) {
            userCommandArgs << " ";
        }
    }

    userFile.create(commArgs[0], userCommandArgs);
}