#include "JSONCheck.hpp"

#include "../JSONStruct/JSONString.hpp"
#include "../JSONStruct/JSONBool.hpp"
#include "../JSONStruct/JSONNum.hpp"


string JsonCheck::inputString(stringstream& fileStream) {
    char checkSymbol = fileStream.get();
    // vector<char> key;
    string key;
    while (checkSymbol != '\"') {
        key += checkSymbol;
        checkSymbol = fileStream.get();
    }

    return key;
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
    return checkSymbol > '0' && checkSymbol < '9';
}

bool JsonCheck::isItKeyWord(stringstream& fileStream, char symbolObjType) {
    char nextLetter = 0;
    bool isRight = 0;
    switch (symbolObjType)
    {
        case 't':
        //TODO: fix
            nextLetter = fileStream.get();
            if (nextLetter != 'r' || nextLetter != 'u' || nextLetter != 'e') {
                throw std::runtime_error("The value should have been \"true\"");
            }
            else {
                isRight = 1;
            }
            break;
        case 'f':
            nextLetter = fileStream.get();
            if (nextLetter != 'a' || nextLetter != 'l' || nextLetter != 's' || nextLetter != 'e') {
                return 0;
                throw std::runtime_error("The value should have been \"false\"");
            }
            else {
                isRight = 1;
            }
            break;
        case 'n':
            nextLetter = fileStream.get();
            if (nextLetter != 'u' || nextLetter != 'l' || nextLetter != 'l') {
                return 0;
                throw std::runtime_error("The value should have been \"null\"");
            }
            else {
                isRight = 1;
            }
            break;
    }
    return isRight;
}

JsonArray* JsonCheck::inputArray(stringstream& fileStream) {
    char checkSymbol = fileStream.get();

    if (checkSymbol == ']') {
        return new JsonArray;
    }

    vector<JsonValue*> valuesArray;

    if (checkSymbol == ' ') {
        checkSymbol = inputWhitespace(fileStream);
    }
    else {
        do {
            if (checkSymbol == ',') {
                checkSymbol = inputWhitespace(fileStream);
            }
            valuesArray.push_back(inputValue(fileStream, checkSymbol));
            checkSymbol = fileStream.get();
        } while (checkSymbol == ',');

        if (isItWhitespace(checkSymbol)) {
            checkSymbol = inputWhitespace(fileStream);
        }
        
        if (checkSymbol != ']') {
            throw std::runtime_error("The array should be closed with \']\'");
        }
    }

    return new JsonArray(valuesArray);
}

JsonValue* JsonCheck::inputValue(stringstream& fileStream, char symbolObjType) {
    string valueOfKey = "";
    double number = 0;
    switch (symbolObjType)
    {
    case '{':
        return inputObject(fileStream);
        break;
    case '[':
        return inputArray(fileStream);
        break;
    case '\"':
        valueOfKey = inputString(fileStream);
        return new JsonString(valueOfKey);
    case 't':
        if (isItKeyWord(fileStream, symbolObjType)) {
            return new JsonBool(true);
        }
        break;
    case 'f':
        if (isItKeyWord(fileStream, symbolObjType)) {
            return new JsonBool(false);
        }       
        break;
    case 'n':
        if (isItKeyWord(fileStream, symbolObjType)) {
            return nullptr;
        }
        break;
    default:
        if (isItDigit(symbolObjType)) {
            number = (double)symbolObjType - '0';
            return new JsonNumber(number);
        }
        else {
            throw std::runtime_error("Unknown value!");
        }
        break;
    }
}

JsonObject* JsonCheck::inputObject (stringstream& fileStream) {
    checkSymbol = inputWhitespace(fileStream);
            cout << "#" << checkSymbol << " ";
    
    // if (checkSymbol != '{') {
    //     throw std::runtime_error("It should start with '{'");
    // }

    vector<string> userKeys;
    vector<JsonValue*> userValues;


    if (checkSymbol == '\"') {
            cout << "#" << checkSymbol << " ";

        string key, value;
        
        do {
            if (checkSymbol == ',') {
                checkSymbol = inputWhitespace(fileStream);
                if (checkSymbol != '\"') {
                    throw std::runtime_error("Not a valid JSON object! Each key starts and ends with \" \" ");
                }
            }
            key = inputString(fileStream);

            checkSymbol = inputWhitespace(fileStream);

            if (checkSymbol != ':') {
                throw std::runtime_error("Expected a : between the key and its value!");
            }
            
                checkSymbol = inputWhitespace(fileStream);
                userValues.push_back(inputValue(fileStream, checkSymbol));
                userKeys.push_back(key);
                checkSymbol = fileStream.get();
            cout << "#" << checkSymbol << " ";
        } while (checkSymbol == ',');

        if (checkSymbol != '}') {
            throw std::runtime_error("Expected a '}' as a closing character of an object!");           
        }

    }
        return new JsonObject(userKeys, userValues);
}

JsonValue* JsonCheck::inputJson (stringstream& fileStream) {
    char checkSymbol = inputWhitespace(fileStream);
    switch (checkSymbol)
    {
    case '{' :
        return inputObject(fileStream);    
        // break;
    case '[' :
        return inputArray(fileStream);
    default:
        throw std::runtime_error("Non-valid json object found!");
        break;
    }
}

void JsonCheck::checkJsonFile() {

}