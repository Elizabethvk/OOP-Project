#include "JSONNum.hpp"

JsonNumber::JsonNumber() 
    : number(0)
{
    type = JSONNUMBER;
}

JsonNumber::JsonNumber(const double& number) 
    : number(number)
{ 
    type = JSONNUMBER;
}

Type JsonNumber::getType()const {
    return type;
}

void JsonNumber::edit(const double& number) {
    this->number = number;
}

double JsonNumber::getJsonNumber() const {
    return number;
}

void JsonNumber::save(ofstream& userFile) const {
    userFile << number;
}

void JsonNumber::print() const {
    cout << number;
}
