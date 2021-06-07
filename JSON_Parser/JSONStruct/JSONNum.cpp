#include "JSONNum.hpp"


JsonNumber::JsonNumber(const double& number) 
    : number(number)
{ 
}

double JsonNumber::getNumber() const {
    return number;
}

void JsonNumber::print() const {
    cout << number << ", " << endl;
}