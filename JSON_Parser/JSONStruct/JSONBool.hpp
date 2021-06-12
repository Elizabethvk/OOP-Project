#ifndef JSONBOOL_H
#define JSONBOOL_H

#include "JSONValue.hpp"

class JsonBool : public JsonValue {
private:
    bool value;

public:
    JsonBool();

    JsonBool(const bool& value);

    Type getType()const;

    bool getValue() const;
    
    void edit(const bool& variable); 

    bool getJsonBool() const;

    void save(ofstream& userFile) const; 

    void keySearch(const string& key) const;

    void printValue() const;

    void print() const;
};


#endif