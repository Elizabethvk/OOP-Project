/**
 * \brief A Class controlling the Search command
 * \author Elizabet Velikova
 */


#ifndef SEARCH_H
#define SEARCH_H

#include "ICommand.hpp"

class CommandSearch : public ICommand {
public:
    //! Default Constructor
    CommandSearch();

    //! Running the command from here    
    void runCommand(JsonCheck& userFile);
};

#endif
