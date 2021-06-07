#ifndef JSONOBJECT_H
#define JSONOBJECT_H


#include "JSONValue.hpp"

class JsonObject : public JsonValue {
private:
    vector<string> keys;
    vector<JsonValue*> values;

    
public:
    JsonObject(const vector<string>& keys, const vector<JsonValue*>& values);
    vector<string> getKeys() const;
    vector<JsonValue*> getJsonValues() const;

    void print() const;

};

#endif