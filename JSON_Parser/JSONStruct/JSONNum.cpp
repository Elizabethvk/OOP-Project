#include "JSONNum.hpp"

JsonNumber::JsonNumber() {
    type = JSONNUMBER;
    number = 0;
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

double JsonNumber::getNumber() const {
    return number;
}

void JsonNumber::keySearch(const string& key) const {
    printValue();
}

void JsonNumber::printValue() const {
    cout << number;
}

void JsonNumber::print() const {
    cout << number;
    // printValue();
    // cout << ", " << endl;
}
