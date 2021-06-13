/**
 * \brief A Class controlling the Close command
 * \author Elizabet Velikova
 */


#ifndef CLOSE_H
#define CLOSE_H

#include "ICommand.hpp"

class CommandClose : public ICommand {
public:
    //! Default Constructor
    CommandClose();
    
    //! Running the command from here
    void runCommand(JsonCheck& userFile);
};

#endif
