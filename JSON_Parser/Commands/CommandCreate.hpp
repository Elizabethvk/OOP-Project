/**
 * \brief A Class controlling the Create command
 * \author Elizabet Velikova
 */


#ifndef CREATE_H
#define CREATE_H

#include "ICommand.hpp"

class CommandCreate : public ICommand {
public:
    //! Default Constructor
    CommandCreate();
    
    //! Running the command from here
    void runCommand(JsonCheck& userFile);
};

#endif