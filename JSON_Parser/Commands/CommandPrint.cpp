#include "CommandPrint.hpp" 



CommandPrint::CommandPrint()
    : ICommand("print")
{
}

void CommandPrint::runCommand(JsonCheck& userFile) {
    assert(commArgs.empty());
    
    userFile.print();
}