/**
 * \brief A Class controlling the Save command
 * \author Elizabet Velikova
 */


#ifndef SAVE_H
#define SAVE_H

#include "ICommand.hpp"

class CommandSave : public ICommand {
public:
    //! Default Constructor
    CommandSave();
    
    //! Running the command from here
    void runCommand(JsonCheck& userFile);
};

#endif

