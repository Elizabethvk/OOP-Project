#include "CommandFileOpen.hpp"
         
CommandFileOpen::CommandFileOpen() 
    : ICommand("open")
{    
}

void CommandFileOpen::runCommand(JsonCheck& userFile) {
    assert(commArgs.size() == 1);

    cout << "Loading the data from the file ..." << endl;
    userFile.openFile(commArgs[0]);
}
