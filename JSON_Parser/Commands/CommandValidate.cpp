#include "CommandValidate.hpp" 

void CommandValidate::executeCmmd(JsonCheck& userFile) {
    assert(commArgs.empty());
    userFile.checkJsonFile();

}