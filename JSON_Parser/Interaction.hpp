/**
 * \brief Class which does the whole work and everything starts here
 * \author Elizabet Velikova
 */


#ifndef INTERACTION_H
#define INTERACTION_H

#include <iterator>
#include <memory>

#include "Commands/ICommand.hpp"
#include "JSONCheck/JSONCheck.hpp"

class Interaction {
private:
    JsonCheck jsonChecker; //!< Stores the JSON file

    vector<std::unique_ptr<ICommand>> userCommands; //!< Stores all available commands

    //! Function for getting the command from the user
    void getCommand(const string& command);

    //! Function for running user's command of choice
    void runCommand(const string& command, vector<string> arguments);

    //! Function for converting first word in string to lowercase word
    void toLower(string& command);

    //! Function to add all commands to userCommands
    void loadCommands();
    
public:
    //! Constructor which makes unique ptrs to the commands
    Interaction();

    //! Constructor that takes command line argument
    Interaction(const string& path);

    //! A function accepting user's commands
    void start();
};


#endif