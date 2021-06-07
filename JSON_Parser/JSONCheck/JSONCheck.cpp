#include "JSONCheck.hpp"

#include "../JSONStruct/JSONString.hpp"
#include "../JSONStruct/JSONBool.hpp"
#include "../JSONStruct/JSONNum.hpp"


string JsonCheck::inputString(stringstream& fileStream) {
    
}

char JsonCheck::inputWhitespace(stringstream& fileStream) {
    char checkSymbol = fileStream.get();

    while (allWhitespace.find(checkSymbol) != string::npos) {
        checkSymbol = fileStream.get();
    }

    return checkSymbol;
}

bool JsonCheck::isItWhitespace(const char& checkSymbol) const {
    return allWhitespace.find(checkSymbol) != string::npos;
}

bool JsonCheck::isItDigit(const char& checkSymbol) const {

}

JsonArray* JsonCheck::inputArray(stringstream& fileStream) {

}

JsonValue* JsonCheck::inputValue(stringstream& fileStream, const char& symbol) {

}

JsonObject* JsonCheck::inputObject (stringstream& fileStream) {

}

JsonValue* JsonCheck::inputJson (stringstream& fileStream) {

}

void JsonCheck::checkJsonFile() {

}