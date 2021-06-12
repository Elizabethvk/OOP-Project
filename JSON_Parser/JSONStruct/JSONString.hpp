/**
 * \brief Class for the String variables in JSON Document
 * \author Elizabet Velikova
 */

#ifndef JSONSTRING_H
#define JSONSTRING_H_H

#include "JSONValue.hpp"

class JsonString : public JsonValue {
private:
    string value; //!< Variable holding the value of the key

public:
    //! Default constructor
    JsonString();

    //! Constructor with already given value
    explicit JsonString(const string& userValue);

    //! Function getting the type
    Type getType() const;
    
    //! Function which saves to a file
    void save(ofstream& userFile) const; 

    //! Getter for the string value
    string getJsonStringValue() const;

    //! Changing the value
    void edit(const string& newValue);
    
    //! Printing the value
    void print() const;
};

#endif