#ifndef JSONCHECK_H
#define JSONCHECK_H

#include "../JSONStruct/JSONValue.hpp"
#include "../JSONStruct/JSONArray.hpp"
#include "../JSONStruct/JSONObject.hpp"

#include <fstream>
#include <sstream>
using std::stringstream;

class JsonCheck {
private:
    const string fileName;
    const string allWhitespace = " \n\r\t";
    char checkSymbol;
    
    string inputString(stringstream& fileStream);
    char inputWhitespace(stringstream& fileStream);
    bool isItWhitespace(const char& checkSymbol) const;
    bool isItDigit(const char& checkSymbol) const;
    bool isItKeyWord(stringstream& fileStream, char symbolObjType);
    bool inputLiteral(stringstream& fileStream, const string& str);

    bool isItOperation(const char& ch) const;
    char whichOperation(const char& ch);

    JsonArray* inputArray(stringstream& fileStream);
    JsonValue* inputValue(stringstream& fileStream, char symbolObjType);
    JsonObject* inputObject(stringstream& fileStream);
    JsonValue* inputNumber(stringstream& fileStream, char symbolObjType);

public:
    JsonCheck() = default;
    JsonValue* inputJson(stringstream& fileStream);

    double getNumber (stringstream& fileStream, char& ch);
    double getNumberE (stringstream& fileStream, char& ch);
    void checkJsonFile();

};



#endif