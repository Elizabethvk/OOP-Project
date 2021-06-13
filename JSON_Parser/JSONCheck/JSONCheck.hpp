/**
 * \brief A Class which is in the core of the whole project, from here is everything controlled
 * \author Elizabet Velikova
 */


#ifndef JSONCHECK_H
#define JSONCHECK_H

#include "../Custom Exceptions/NotAValue.h"
#include "../Custom Exceptions/NotAValidArrayOpen.h"
#include "../Custom Exceptions/NotAValidArrayClose.h"

#include "../ControlVariables/ControlVariables.hpp"

#include "../JSONStruct/JSONObject.hpp"
#include "../JSONStruct/JSONValue.hpp"
#include "../JSONStruct/JSONBool.hpp"
#include "../JSONStruct/JSONArray.hpp"


#include <sstream>
using std::stringstream;


class JsonCheck {
private:
    string fileName; //!< A variable holding the name of the current file
    char checkSymbol; //!< A variable holding the current checking char
    const string allWhitespace = " \n\r\t"; //!< A variable holding the available whitespace
    stringstream fileStream; //!< A variable holding file stream in string
    bool isJsonLoaded; //!< A variable holding checking if a file is open
    JsonObject* jsonFile; //!< A variable holding the whole file

    // JsonValue* openCreate();
    
private:
    //! Helper functions:

    //! A function for moving the pointer to a place with a valid symbol
    char inputWhitespace(stringstream& fileStream) const;

    //! A function cheking wether the char is a whitespace
    bool isItWhitespace(const char& checkSymbol) const;

    //! A function cheking wether the char is a digit
    bool isItDigit(const char& checkSymbol) const;

    //! A function cheking wether the char is an operation
    bool isItOperation(const char& ch) const;

    //! A function cheking which function is the char
    char whichOperation(const char& ch) const;

    //! A function cheking wether the char is a literal
    bool inputLiteral(stringstream& fileStream, const string& str) const;

    // bool isItKeyWord(stringstream& fileStream, char symbolObjType);

    //! A function getting as an input a number
    double getNumber (stringstream& fileStream, char& ch) const;

    //! A function getting as an input a number with scientific notation E/e
    double getNumberE (stringstream& fileStream, char& ch) const;


    //! A function cheking user's answer 
    void checkAnswer(int& answer);

    //! A function converting a string to int number
    int stringToInt(const string& str);

    //! A function for parsing the desired changes which are pending to be made in the file
    vector<ControlVariables> parsingCommand (const string& command);

private: 
    //! Reading the JSON file:

    //! A function getting the string as an input
    string inputString(stringstream& fileStream, char checkSymbol) const;

    //! A function getting an array as an input
    JsonArray* inputArray(stringstream& fileStream) const;

    //! A function getting a value as an input
    JsonValue* inputValue(stringstream& fileStream, char symbolObjType) const;

    //! A function getting an object as an input
    JsonObject* inputObject(stringstream& fileStream, char checkSymbol) const;

    //! A function getting a number as an input
    JsonValue* inputNumber(stringstream& fileStream, char symbolObjType) const;
    
    //! A function getting a json value as an input
    JsonValue* inputJson(stringstream& fileStream) const;

    // JsonBool* keyWords(stringstream& fileStream, char symbolObjType);

public:
    //! Default contructor
    JsonCheck();

    // JsonCheck(const string& fileInfo);

    //! The file open function
    void openFile(const string& filePath);    

    //! The validate file function
    bool checkJsonFile();

    //! The create new key with value in file function
    void create (const string& str, stringstream& fileStream);

    //! The search in file function
    void searchInFile(const string& str) const;

    //! The edit file function
    void edit (const string& str, stringstream& fileStream);

    //! The remove by path and key function
    void removeByPath(const string& key);

    //! The close file function
    void closeFile();

    //! The save file function
    void saveFile();

    //! The save as file function
    void saveAsFile(const string& newFileName);

    //! The exiting function
    void terminateFunction();

    //! The printing file function
    void print() const; // Check todo

    //! Function printing the menu
    void help() const;

};



#endif