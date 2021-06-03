#include "JSONString.hpp"

JsonString::JsonString(const string& userValue) 
    : value(userValue)
{
}

string JsonString::getValue() const {
    return value;
}

void JsonString::print() const {
    cout << ' ' << "\"" << value << "\"" << ", " << endl;
}