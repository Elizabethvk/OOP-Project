/**
 * \brief An abstract class holding all the needed functions for children command classes
 * \author Elizabet Velikova
 */

#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <cassert>
#define NDEBUG

#include "../JSONCheck/JSONCheck.hpp"


class ICommand {
protected:
    string command; //!< Whole user command
    vector <string> commArgs; //! Each argument of the command without the command itself

public:
    //! Default Constructor
    ICommand() = default;

    //! Constructor taking user commands
    ICommand(const string& userCommand);

    //! Rule of 3 destructor
    virtual ~ICommand() = default;

    //! Running the command from here
    virtual void runCommand( JsonCheck& userFile);
    
    //! Setting the arguments of the program
    void setArgs(vector<string>& args);

    //! Getting the command as a string
    string& getCommand();

};


#endif