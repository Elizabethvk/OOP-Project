#include "CommandValidate.hpp" 

void CommandValidate::runCommand(JsonCheck& userFile) {
    assert(commArgs.empty());
    userFile.checkJsonFile();

}