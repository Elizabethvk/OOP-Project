#include "CommandSave.hpp"



CommandSave::CommandSave() 
    : ICommand("save")
{
}


void CommandSave::runCommand(JsonCheck& userFile) {
   
   // assert(commArgs.empty());

    userFile.saveFile();
}