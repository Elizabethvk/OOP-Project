#ifndef JSONNUMBER_H
#define JSONNUMBER_H

#include "JSONValue.hpp"

class JsonNumber : public JsonValue {
private:
    double number;

public:
    JsonNumber();

    explicit JsonNumber(const double& number);

    Type getType()const;

    void edit(const double& number);

    double getJsonNumber() const;

    void save(ofstream& userFile) const; 

    double getNumber() const;

    void keySearch(const string& key) const;

    void printValue() const;

    void print() const;


};

#endif