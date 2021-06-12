#ifndef JSONCHECK_H
#define JSONCHECK_H

#include "../ControlVariables/ControlVariables.hpp"

#include "../JSONStruct/JSONValue.hpp"
#include "../JSONStruct/JSONBool.hpp"
#include "../JSONStruct/JSONArray.hpp"
#include "../JSONStruct/JSONObject.hpp"

#include <sstream>
using std::stringstream;


class JsonCheck {
private:
    string fileName;
    const string allWhitespace = " \n\r\t";
    char checkSymbol;
    stringstream fileStream;
    bool isJsonLoaded;
    JsonObject* jsonFile;

    JsonValue* openCreate();
    
private:
    char inputWhitespace(stringstream& fileStream) const;
    bool isItWhitespace(const char& checkSymbol) const;
    bool isItDigit(const char& checkSymbol) const;
    bool isItOperation(const char& ch) const;
    char whichOperation(const char& ch) const;
    bool inputLiteral(stringstream& fileStream, const string& str) const;
    // bool isItKeyWord(stringstream& fileStream, char symbolObjType);
    double getNumber (stringstream& fileStream, char& ch) const;
    double getNumberE (stringstream& fileStream, char& ch) const;

    void checkAnswer(int& answer);
    int stringToInt(const string& str);
    vector<ControlVariables> parsingCommand (const string& command);

    string inputString(stringstream& fileStream, char checkSymbol) const;
    JsonArray* inputArray(stringstream& fileStream) const;
    JsonValue* inputValue(stringstream& fileStream, char symbolObjType) const;
    JsonObject* inputObject(stringstream& fileStream, char checkSymbol) const;
    JsonValue* inputNumber(stringstream& fileStream, char symbolObjType) const;
    JsonValue* inputJson(stringstream& fileStream) const;
    // JsonBool* keyWords(stringstream& fileStream, char symbolObjType);

public:
    JsonCheck();

    // JsonCheck(const string& fileInfo);

    void help() const;

    bool checkJsonFile();

    void openFile(const string& filePath);    

    void closeFile();

    void saveFile();

    void saveAsFile(const string& newFileName);

    void create (const string& str, stringstream& fileStream);

    void edit (const string& str, stringstream& fileStream);

    void terminateFunction();

    void removeByPath(const string& key);

    void searchInFile(const string& str) const;

    void print() const; // Check todo

};



#endif