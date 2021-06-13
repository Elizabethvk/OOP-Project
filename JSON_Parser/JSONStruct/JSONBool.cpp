#include "JSONBool.hpp"

JsonBool::JsonBool() {
    type = JSONBOOL;
}

JsonBool::JsonBool(const bool& value) 
    : value(value)
{
    type = JSONBOOL;
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


void JsonBool::print() const {
    value ? cout << "true" : cout << "false";
}
