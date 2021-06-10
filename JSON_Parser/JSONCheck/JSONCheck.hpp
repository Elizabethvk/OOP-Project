#ifndef JSONCHECK_H
#define JSONCHECK_H

#include "../JSONStruct/JSONValue.hpp"
#include "../JSONStruct/JSONBool.hpp"
#include "../JSONStruct/JSONArray.hpp"
#include "../JSONStruct/JSONObject.hpp"

#include <fstream>
#include <sstream>
using std::stringstream;
using std::ifstream;
using std::ofstream;

class JsonCheck {
private:
    const string fileName;
    const string allWhitespace = " \n\r\t";
    char checkSymbol;

    stringstream openFile();
    JsonValue* openCreate();
    
    char inputWhitespace(stringstream& fileStream);
    bool isItWhitespace(const char& checkSymbol) const;
    bool isItDigit(const char& checkSymbol) const;
    bool isItOperation(const char& ch) const;
    char whichOperation(const char& ch);
    bool inputLiteral(stringstream& fileStream, const string& str);
    // bool isItKeyWord(stringstream& fileStream, char symbolObjType);
    double getNumber (stringstream& fileStream, char& ch);
    double getNumberE (stringstream& fileStream, char& ch);


    string inputString(stringstream& fileStream, char checkSymbol);
    JsonArray* inputArray(stringstream& fileStream);
    JsonValue* inputValue(stringstream& fileStream, char symbolObjType);
    JsonObject* inputObject(stringstream& fileStream, char checkSymbol);
    JsonValue* inputNumber(stringstream& fileStream, char symbolObjType);
    JsonValue* inputJson(stringstream& fileStream);
    // JsonBool* keyWords(stringstream& fileStream, char symbolObjType);

public:
    JsonCheck(const string& fileInfo);

    bool checkJsonFile();

    void searchInFile(const string& str);

    void print();

};



#endif