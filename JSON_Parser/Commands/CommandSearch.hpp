#ifndef SEARCH_H
#define SEARCH_H

#include "ICommand.hpp"

class CommandSearch : public ICommand {
public:
    CommandSearch();
    
    void runCommand(JsonCheck& userFile);
};

#endif
