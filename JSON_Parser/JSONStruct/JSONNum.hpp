#ifndef JSONNUMBER_H
#define JSONNUMBER_H

#include "JSONValue.hpp"

class JsonNumber : public JsonValue {
private:
    double number;

public:
    JsonNumber(const double& number);
    double getNumber() const;

    void keySearch(const string& key) const;

    void printValue() const;

    void print() const;


};

#endif