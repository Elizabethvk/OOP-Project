#include "Interaction.hpp"

#include "Commands/CommandHelp.hpp"
#include "Commands/CommandFileOpen.hpp"
#include "Commands/CommandValidate.hpp"
#include "Commands/CommandSearch.hpp"
#include "Commands/CommandPrint.hpp"
#include "Commands/CommandClose.hpp"

void Interaction::getCommand(const string& command) {
    string whichCommand, commandArgs;
    vector<string> commandArguments;

    stringstream commandStream;
    commandStream << command;
    
    commandStream >> whichCommand;

    while (commandStream >> commandArgs) {
        commandArguments.push_back(commandArgs);
    }

    runCommand(whichCommand, commandArguments);
}

void Interaction::runCommand(const string& command, vector<string> arguments) {
    bool isFound = false;
    vector<std::unique_ptr<ICommand>>::iterator itCommands;

    for (itCommands = userCommands.begin(); itCommands < userCommands.end(); ++itCommands) {
        if ((*itCommands)->getCommand() == command) {
            (*itCommands)->setArgs(arguments);
            (*itCommands)->runCommand(jsonChecker);
            isFound = true;
        }
    }
    if (!isFound) {
        cout << "No command with the name " << command << " found!" << endl;
        cout << "Type in \"help\" in order to see the commands' list!" << endl;
    }
}


Interaction::Interaction() {
    userCommands.push_back(std::make_unique<CommandHelp>());
    userCommands.push_back(std::make_unique<CommandFileOpen>());
    userCommands.push_back(std::make_unique<CommandValidate>());
    userCommands.push_back(std::make_unique<CommandSearch>());
    userCommands.push_back(std::make_unique<CommandPrint>());
    userCommands.push_back(std::make_unique<CommandClose>());
}

void Interaction::start() {
    string userCommand;

    while (true) {
        cout << "> ";
        getline (cin, userCommand);
        getCommand(userCommand);
    }
}