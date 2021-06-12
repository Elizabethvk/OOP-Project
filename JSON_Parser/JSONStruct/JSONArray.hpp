#ifndef JSONARRAY_H
#define JSONARRAY_H

#include <iterator>

#include "JSONValue.hpp"

class JsonArray : public JsonValue {
private:
    vector<JsonValue*> values;

public:
    JsonArray();
    
    explicit JsonArray(const vector<JsonValue*>& values);
    
    vector<JsonValue*> getValues() const;

    Type getType() const;

    void edit(const int& valueNrconst, JsonValue* value); 
    
    // void edit(const int& valueNrconst, JsonValue* value); 

    void save(ofstream& userFile) ; 

    void keySearch(const string& key) const;

    void printArrElements() const;

    void printValue(std::ostream& out);

    void print();
};

#endif