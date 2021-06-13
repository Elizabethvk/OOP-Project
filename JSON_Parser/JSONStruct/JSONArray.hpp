/**
 * \brief Class Array holding a key and multiple values
 * \author Elizabet Velikova
 */

#ifndef JSONARRAY_H
#define JSONARRAY_H

#include <iterator>

#include "JSONValue.hpp"

class JsonArray : public JsonValue {
private:
    static int openBracketsCounterArr; //!< Variable counting the open brackets

    vector<JsonValue*> values; //!< Vector that holds key's values

public:
    //! Default constructor
    JsonArray();
    
    //! Constructor with already given values
    explicit JsonArray(const vector<JsonValue*>& values);
    
    //! Function getting the type
    Type getType() const;

    //! Changing specific value
    void edit(const int& valueNrconst, JsonValue* value); 
    
    //! Changing a value of the key
    void editValue(const string& newValue);

    //! Function which saves to a file
    void save(ofstream& userFile) const; 

    //! Printing the value
    void print() const;
};

#endif