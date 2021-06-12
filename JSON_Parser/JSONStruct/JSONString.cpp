#include "JSONString.hpp"



JsonString::JsonString() 
{
    type = JSONSTRING;
}


JsonString::JsonString(const string& userValue) 
    : value(userValue)
{
    type = JSONSTRING;
}


Type JsonString::getType() const {
    return type;
}

void JsonString::save(ofstream& userFile) const {
    userFile << "\"" << value << "\"";
} 

string JsonString::getJsonStringValue() const {
    return value;
}

void JsonString::edit(const string& newValue) {
    value = newValue;
}


void JsonString::print() const {
    cout << "\"" << value << "\"";
}