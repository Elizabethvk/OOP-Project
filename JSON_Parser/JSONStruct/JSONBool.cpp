#include "JSONBool.hpp"

JsonBool::JsonBool(const bool& value) 
    : value(value)
{
}


bool JsonBool::getValue() const {
    return value;
}

void JsonBool::print() const {
    cout << value << "," << endl;
}
