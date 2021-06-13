/**
 * \brief A Class controlling the Edit command
 * \author Elizabet Velikova
 */

#ifndef EDIT_H
#define EDIT_H

#include "ICommand.hpp"

class CommandEdit : public ICommand {
public:
    //! Default Constructor
    CommandEdit();
    
    //! Running the command from here
    void runCommand(JsonCheck& userFile);
};

#endif
