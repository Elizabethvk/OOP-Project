/**
 * \brief Class for Bool JSON type
 * \author Elizabet Velikova
 */


#ifndef JSONBOOL_H
#define JSONBOOL_H

#include "JSONValue.hpp"

class JsonBool : public JsonValue {
private:
    bool value; //!< Holds the bool value

public:
    //! Default constructor
    JsonBool();

    //! Constructor with already given value
    JsonBool(const bool& value);

    //! Function getting the type
    Type getType()const;
    
    //! Changing the value
    void edit(const bool& variable); 

    //! Getter for the bool value
    bool getJsonBool() const;

    //! Function which saves to a file
    void save(ofstream& userFile) const; 

    //! Printing the value
    void print() const;
};


#endif