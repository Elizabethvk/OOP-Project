#ifndef INTERACTION_H
#define INTERACTION_H

#include <memory>

#include "Commands/ICommand.hpp"
#include "JSONCheck/JSONCheck.hpp"

class Interaction {
private:
    JsonCheck jsonChecker;

    vector<std::unique_ptr<ICommand()>> userCommands;

    void getCommand(const string& command);
    // void applyArguments(const string& commandName, vector<string> arguments);

public:
    Interaction();
    void run();
};


#endif