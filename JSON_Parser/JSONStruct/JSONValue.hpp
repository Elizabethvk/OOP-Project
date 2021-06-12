/**
 * \brief Abstract Class which holds pure virtual function and it is the base of all JSON Values
 * \author Elizabet Velikova
 */

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

#include <fstream>
using std::ifstream;
using std::ofstream;

#include "enumTypes.hpp"

class JsonValue {
private:
//
protected:
    Type type; //!< Holds the types of JSON values
public:
    virtual void save(ofstream& userFile) const = 0; 

    virtual string getJsonStringValue() const;

    virtual bool getJsonBool() const;

    virtual double getJsonNumber() const;

    virtual Type getType() const = 0;

    virtual void keySearch(const string& key) const = 0;

    virtual void removeByKey(const string& key);

    virtual void printValue() const = 0;

    virtual void print() const = 0;
};

#endif