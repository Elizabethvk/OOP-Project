#include "JSONBool.hpp"

JsonBool::JsonBool() {
    type = JSONBOOL;
}

JsonBool::JsonBool(const bool& value) 
    : value(value)
{
    type = JSONBOOL;
}


bool JsonBool::getValue() const {
    return value;
}

Type JsonBool::getType()const {
    return type;
}

void JsonBool::edit(const bool& variable) {
    value = variable;
}

bool JsonBool::getJsonBool() const {
    return value;
}

void JsonBool::save(ofstream& userFile) const {
    value ? userFile << "true" : userFile << "false";
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
