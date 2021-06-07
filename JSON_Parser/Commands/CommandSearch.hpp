#ifndef SEARCH_H
#define SEARCH_H

#include "ICommand.hpp"

class CommandSearch : public ICommand {
private:
    CommandSearch();
    
    void executeCmmd(JsonCheck& userFile);
};

#endif
