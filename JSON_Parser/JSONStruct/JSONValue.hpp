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

#include <cmath>


class JsonValue {
private:
//
public:
    virtual void keySearch(const string& key) const = 0;

    virtual void printValue() const = 0;

    virtual void print() const = 0;
    // friend std::istream& operator<<(std::istream& out, JsonValue sample);
};

#endif