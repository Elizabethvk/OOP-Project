#include "CommandSearch.hpp"

CommandSearch::CommandSearch() 
    : ICommand("search")
{   
}

void CommandSearch::runCommand(JsonCheck& userFile) {
   // assert(commArgs.size() == 1);
    if (commArgs.empty()) {
        cout << "No parameters found." << endl;
        return;
    }
    userFile.searchInFile(commArgs[0]);
}