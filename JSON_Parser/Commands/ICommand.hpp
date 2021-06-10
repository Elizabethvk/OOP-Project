#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <cassert>
#define NDEBUG

#include "../JSONCheck/JSONCheck.hpp"

// #include <vector>
// #include <string>
// using std::string; 
// using std::vector;


class ICommand {
protected:
    string command;
    vector <string> commArgs;

public:
    ICommand() = default;
    ICommand(const string& userCommand);
    virtual ~ICommand() = default;

    virtual void executeCmmd( JsonCheck& userFile);
    void setArgs(vector<string>& args);

    string& getCommand();


};


#endif