#ifndef JSONSTRING_H
#define JSONSTRING_H_H

#include "JSONValue.hpp"

class JsonString : public JsonValue {
private:
    string value;

public:
    void save(ofstream& userFile) const; 

    string getJsonStringValue() const;

    bool getJsonBool() const;

    double getJsonNumber() const;

    Type getType() const;

    void edit(const string& str);

    void keySearch(const string& key) const;

    JsonString();

    explicit JsonString(const string& userValue);

    void keySearch(const string& key) const;

    void printValue() const;
    // string getValue() const;
    void print() const;
};

#endif