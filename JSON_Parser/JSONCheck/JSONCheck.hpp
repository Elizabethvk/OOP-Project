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
    
    string inputString(stringstream& fileStream);
    char inputWhitespace(stringstream& fileStream);
    bool isItWhitespace(const char& checkSymbol) const;
    bool isItDigit(const char& checkSymbol) const;

    JsonArray* inputArray(stringstream& fileStream);
    JsonValue* inputValue(stringstream& fileStream, const char& symbol);
    JsonObject* inputObject(stringstream& fileStream);

public:
    JsonValue* inputJson(stringstream& fileStream);

    void checkJsonFile();

};



#endif