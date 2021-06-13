/**
 * \brief A Class controlling the Move command
 * \author Elizabet Velikova
 */


#ifndef MOVE_H
#define MOVE_H

#include "ICommand.hpp"

class CommandMove : public ICommand {
public:
    //! Default Constructor
    CommandMove();
    
    //! Running the command from here
    void runCommand(JsonCheck& userFile);
};

#endif