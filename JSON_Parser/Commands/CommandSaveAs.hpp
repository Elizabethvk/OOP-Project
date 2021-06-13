/**
 * \brief A Class controlling the Save As command
 * \author Elizabet Velikova
 */


#ifndef SAVE_AS_H
#define SAVE_AS_H

#include "ICommand.hpp"

class CommandSaveAs : public ICommand {
public:
    //! Default Constructor
    CommandSaveAs();
    
    //! Running the command from here
    void runCommand(JsonCheck& userFile);
};

#endif
