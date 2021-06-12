/**
 * \brief Class which holds and takes care of the keys and values when chaning them with the command
 * \author Elizabet Velikova
 */


#ifndef CONTROL_VARIABLES_H
#define CONTROL_VARIABLES_H

#include <string>
using std::string;

class ControlVariables {
private:
    string key; //!< Variable that holds the key
    int value; //!< Variable that holds the value/number of the key

public:
    //! Default constructor
    ControlVariables() = default;

    //! Constructor getting what the user want to change
    ControlVariables (const string& userKey, const int& userValue);


    //! Gets the key which is held at the moment
    string getKey() const;

    //! Gets current value number which refers to the key
    int getValue() const;


    //! Chaing current key
    void setKey(const string& userKey);

    //! Changing the key's current value
    void setValue(const int& userValue);
};


#endif