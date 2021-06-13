#include "CommandRemove.hpp"



CommandRemove::CommandRemove() 
    : ICommand("remove")
{
}
    

void CommandRemove::runCommand(JsonCheck& userFile) {
    if (commArgs.empty()) {
        cout << "No parameters found." << endl;
        return;
    }
   // assert(commArgs.size() == 1);

    userFile.removeByPath(commArgs[0]);
}