#ifndef JSONVALUE_H
#define JSONVALUE_H

#include <iostream>
using std::cout; 
using std::cin; 
using std::endl;

class JsonValue {
private:
//
public:
    virtual void print() const = 0;
};

#endif