#include "CommandFileOpen.hpp"
         
CommandFileOpen::CommandFileOpen() 
    : ICommand("open")
{    
}

void CommandFileOpen::runCommand(JsonCheck& userFile) {
    if (commArgs.empty()) {
        cout << "No parameters found." << endl;
        return;
    }
    //assert(commArgs.size() == 1);

    cout << "Loading the data from the file ..." << endl;
    userFile.openFile(commArgs[0]);
}
