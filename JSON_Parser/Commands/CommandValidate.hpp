/**
 * \brief A Class controlling the Validate command
 * \author Elizabet Velikova
 */

#ifndef VALIDATE_H
#define VALIDATE_H

#include "ICommand.hpp"

class CommandValidate : public ICommand {
public:
    //! Default Constructor
    CommandValidate();
    
    //! Running the command from here
    void runCommand(JsonCheck& userFile);
};

#endif
