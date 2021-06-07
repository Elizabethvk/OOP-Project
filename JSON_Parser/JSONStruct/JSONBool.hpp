#ifndef JSONBOOL_H
#define JSONBOOL_H

#include "JSONValue.hpp"

class JsonBool : public JsonValue {
private:
    bool value;

public:
    JsonBool(const bool& value);
    bool getValue() const;
    
    void print() const;
};


#endif