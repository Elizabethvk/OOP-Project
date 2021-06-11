#include "CommandSearch.hpp"

CommandSearch::CommandSearch() 
    : ICommand("search")
{   
}

void CommandSearch::runCommand(JsonCheck& userFile) {
    assert(commArgs.size() == 1);
    userFile.searchInFile(commArgs[0]);
}