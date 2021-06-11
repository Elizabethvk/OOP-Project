#include "JSONString.hpp"

JsonString::JsonString(const string& userValue) 
    : value(userValue)
{
    type = JSONSTRING;
}

JsonString::JsonString() 
{
    type = JSONSTRING;
}

// string JsonString::getValue() const {
//     return value;
// }

void JsonString::save(ofstream& userFile) const {
    userFile << "\"" << value << "\"";
} 

string JsonString::getJsonStringValue() const {
    return value;
}

bool JsonString::getJsonBool() const {

}

double JsonString::getJsonNumber() const {

}

Type JsonString::getType() const {
    return type;
}

void JsonString::edit(const string& str) {
    value = str;
}

void JsonString::keySearch(const string& key) const {

}

void JsonString::keySearch(const string& str) const {
    printValue();
}

void JsonString::printValue() const {
    cout << "\"" << value << "\"";
}

void JsonString::print() const {
    printValue();
    // cout << ", ";
}