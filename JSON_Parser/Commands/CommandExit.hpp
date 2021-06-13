/**
 * \brief A Class controlling the Exit command
 * \author Elizabet Velikova
 */


#ifndef EXIT_H
#define EXIT_H

#include "ICommand.hpp"

class CommandExit : public ICommand {
public:
    //! Default Constructor
    CommandExit();
    
    //! Running the command from here
    void runCommand(JsonCheck& userFile);
};



#endif