#include "JSONNum.hpp"


JsonNumber::JsonNumber(const double& number) 
    : number(number)
{ 
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
    printValue();
    cout << ", " << endl;
}
