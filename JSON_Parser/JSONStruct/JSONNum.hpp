#ifndef JSONNUMBER_H
#define JSONNUMBER_H

#include "JSONValue.hpp"

class JsonNumber : public JsonValue {
private:
    double number;

public:
    JsonNumber(const double& number);
    double getNumber() const;

    void print() const;


};

#endif