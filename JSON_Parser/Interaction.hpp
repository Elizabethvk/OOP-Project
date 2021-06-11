#ifndef INTERACTION_H
#define INTERACTION_H

#include <memory>
#include <iterator>

#include "Commands/ICommand.hpp"
#include "JSONCheck/JSONCheck.hpp"

class Interaction {
private:
    JsonCheck jsonChecker;

    vector<std::unique_ptr<ICommand>> userCommands;

    void getCommand(const string& command);
    void runCommand(const string& command, vector<string> arguments);

public:
    Interaction();
    void start();
};


#endif