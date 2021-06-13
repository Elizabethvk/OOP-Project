#include "CommandSaveAs.hpp"


CommandSaveAs::CommandSaveAs() 
    : ICommand("saveas")
{
}

void CommandSaveAs::runCommand(JsonCheck& userFile) {
    if (commArgs.empty()) {
        cout << "No parameters found." << endl;
        return;
    }
   // assert(commArgs.size() == 1);
    
    userFile.saveAsFile(commArgs[0]);
}