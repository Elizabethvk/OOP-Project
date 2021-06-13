#include "ICommand.hpp"



ICommand::ICommand(const string& userCommand) 
    : command(userCommand)
{    
}


void ICommand::setArgs(vector<string>& args) {
    commArgs = args;
}


string& ICommand::getCommand() {
    return command;
}