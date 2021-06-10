#include "JSONBool.hpp"

JsonBool::JsonBool(const bool& value) 
    : value(value)
{
}


bool JsonBool::getValue() const {
    return value;
}


void JsonBool::keySearch(const string& key) const {
    value ? cout << "true" : cout << "false";
}

void JsonBool::printValue() const {
    value ? cout << "true" : cout << "false";
}

void JsonBool::print() const {
    printValue();
    cout << "," << endl;
}
