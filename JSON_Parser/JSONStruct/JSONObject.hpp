/**
 * \brief Class holding and taking care of the JSON object
 * \author Elizabet Velikova
 */


#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include "JSONValue.hpp"

const unsigned int SPACE_TO_PRINT = 3;

class JsonObject : public JsonValue {
private:
    static int openBracketsCounter; //!< Variable counting the open brackets

    vector<string> keys; //!< Variable holding the keys
    vector<JsonValue*> values; //!< Variable holding keys' values

    //! Function printing more space
    string addSpace(const unsigned int n) const; 


public:
    //! Default constructor
    JsonObject();

    //! Constructor with already given value
    explicit JsonObject(const vector<string>& keys, const vector<JsonValue*>& values);

    //! Function getting the type
    Type getType() const;


    void keyChange(const string& key, JsonValue* value);

    //! Function getting the value by given key
    JsonValue* getValueByKey(const string& key) const;

    //! Function for inserting new value in the object
    void insertNewValue(const string& key, JsonValue* value);

    //! Function for searching by key
    void keySearch(const string& key) const;

    //! Function for changing the value by key
    void edit(const string& key, JsonValue*& value);

    //! Function for checking if the value and the key match
    bool doKeyAndValueMatch(const string& key) const;

    //! Function to remove a value by given key
    void removeByKey(const string& key);

    //! Function which saves to a file
    void save(ofstream& userFile) const; 

    //! Printing the value
    void print() const;
};

#endif