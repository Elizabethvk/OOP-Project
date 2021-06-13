/**
 * \brief Class about JSON Number type
 * \author Elizabet Velikova
 */


#ifndef JSONNUMBER_H
#define JSONNUMBER_H

#include "JSONValue.hpp"

class JsonNumber : public JsonValue {
private:
    double number; //!< Variable double

public:
    //! Default constructor
    JsonNumber();

    //! Constructor with already given value
    explicit JsonNumber(const double& number);

    //! Function getting the type
    Type getType()const;

    //! Changing the value
    void edit(const double& number);

    //! Getter for the double value
    double getJsonNumber() const;

    //! Function which saves to a file
    void save(ofstream& userFile) const; 

    //! Printing the value
    void print() const;

};

#endif