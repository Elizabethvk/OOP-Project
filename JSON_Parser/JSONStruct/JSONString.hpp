#ifndef _H
#define _H

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