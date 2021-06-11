#ifndef JSONOBJECT_H
#define JSONOBJECT_H

// #include <iterator>
#include "JSONValue.hpp"

const unsigned int SPACE_TO_PRINT = 3;

class JsonObject : public JsonValue {
private:

    vector<string> keys;
    vector<JsonValue*> values;

    void addSpace(const unsigned int n) const;

public:
    JsonObject();

    void save(ofstream& userFile) const; 

    string getJsonStringValue() const;

    bool checkByStringKey(const string& str) const;

    bool getJsonBool() const;

    double getJsonNumber() const;

    Type getType() const;

    void edit(const string& str, JsonValue*& value);

    JsonValue* getByKey(const string& key) const;

    explicit JsonObject(const vector<string>& keys, const vector<JsonValue*>& values);
    // vector<string> getKeys() const;
    // vector<JsonValue*> getJsonValues() const;

    // int isItValue(const string& name) const;

    void keySearch(const string& key) const;

    void printValue(std::ostream& out) const;

    void print() const;

};

#endif