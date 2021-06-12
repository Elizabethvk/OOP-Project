#include "CommandFileOpen.hpp"
         
CommandFileOpen::CommandFileOpen() 
    : ICommand("open")
{    
}

void CommandFileOpen::runCommand(JsonCheck& userFile) {
    assert(commArgs.size() == 1);
    cout << "Loading the data from a file ..." << endl;
    userFile.openFile(commArgs[0]);
}
