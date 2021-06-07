#include "ICommand.hpp"

// ICommand::ICommand() 
// {
// }

ICommand::ICommand(const string& userCommand) 
    : command(userCommand)
{    
}

// ICommand::~ICommand() 
// {
// }

// void ICommand::executeCmmd() {

// }

void ICommand::setArgs(vector<string>& args) {
    commArgs = args;
}

string& ICommand::getCommand() {
    return command;
}