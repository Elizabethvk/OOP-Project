#include "ControlVariables.hpp"



ControlVariables::ControlVariables (const string& userKey, const int& userValue) 
    : key(userKey), value(userValue)
{
} 

string ControlVariables::getKey() const {
    return key;
}

int ControlVariables::getValue() const {
    return value;
}


void ControlVariables::setKey(const string& userKey) {
    key = userKey;
}

void ControlVariables::setValue(const int& userValue) {
    value = userValue;
}
