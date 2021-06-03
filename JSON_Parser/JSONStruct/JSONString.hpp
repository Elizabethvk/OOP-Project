#ifndef JSONSTRING_H
#define JSONSTRING_H_H

#include <string>
using std::string;

#include "JSONValue.hpp"

class JsonString : public JsonValue {
private:
    string value;

public:
    JsonString(const string& userValue);

    string getValue() const;
    void print() const;
};

#endif