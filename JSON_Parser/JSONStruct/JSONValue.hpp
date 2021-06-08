#ifndef JSONVALUE_H
#define JSONVALUE_H

#include <iostream>
using std::cout; 
using std::cin; 
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;


class JsonValue {
private:
//
public:
    virtual void print() const = 0;
    // friend std::istream& operator<<(std::istream& out, JsonValue sample);
};

#endif