#ifndef ICOMMAND_H
#define ICOMMAND_H

#include <vector>
#include <string>
using std::string; 
using std::vector;


class ICommand {
private:
    string command;
    vector <string> commArgs;

public:
    ICommand();
    ICommand(const string& userCommand);
    virtual ~ICommand();

    virtual void executeCmmd();
    void setArgs(vector<string>& args);

    string& getCommand();




};


#endif