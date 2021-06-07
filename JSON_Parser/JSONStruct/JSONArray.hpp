#ifndef JSONARRAY_H
#define JSONARRAY_H

#include "JSONValue.hpp"

class JsonArray : public JsonValue {
private:
    vector<JsonValue*> values;
public:
    JsonArray();
    JsonArray(const vector<JsonValue*>& values);
    
    vector<JsonValue*> getValues() const;

    void print() const;
};

#endif