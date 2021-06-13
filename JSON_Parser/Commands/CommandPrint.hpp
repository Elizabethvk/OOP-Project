/**
 * \brief A Class controlling the Print command
 * \author Elizabet Velikova
 */


#ifndef PRINT_H
#define PRINT_H

#include "ICommand.hpp"

class CommandPrint : public ICommand {
public:
    //! Default Constructor
    CommandPrint();
    
    //! Running the command from here
    void runCommand(JsonCheck& userFile);
};

#endif
