#include "JSONString.hpp"

JsonString::JsonString(const string& userValue) 
    : value(userValue)
{
}

// string JsonString::getValue() const {
//     return value;
// }


void JsonString::keySearch(const string& str) const {
    printValue();
}

void JsonString::printValue() const {
    cout << "\"" << value << "\"";
}

void JsonString::print() const {
    printValue();
    cout << ", ";
}