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
    //! Function getter - type
    virtual Type getType() const = 0;

    //! Function getter - string value
    virtual string getJsonStringValue() const {};

    //! Function getter - number
    virtual double getJsonNumber() const {};

    //! Function getter - boolean
    virtual bool getJsonBool() const {};

    //! Function searching in the file by given key
    virtual void keySearch(const string& key) const {};

    //! Function to remove something by given key
    virtual void removeByKey(const string& key) {};

    //! Printing values
    virtual void print() const = 0;

    //! Saving into file
    virtual void save(ofstream& userFile) const = 0; 
};

#endif