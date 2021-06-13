/**
 * \brief A Class controlling the Help command
 * \author Elizabet Velikova
 */


#ifndef HELP_H
#define HELP_H

#include "ICommand.hpp"

class CommandHelp : public ICommand {
public:
    //! Default Constructor
    CommandHelp();
    
    //! Running the command from here
    void runCommand(JsonCheck& userFile);
};

#endif
