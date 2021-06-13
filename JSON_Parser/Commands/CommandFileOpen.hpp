/**
 * \brief A Class controlling the Open File command
 * \author Elizabet Velikova
 */


#ifndef FILE_OPEN_H
#define FILE_OPEN_H

#include "ICommand.hpp"

class CommandFileOpen : public ICommand {
public:
    //! Default Constructor
    CommandFileOpen();
    
    //! Running the command from here
    void runCommand(JsonCheck& userFile);
};

#endif
