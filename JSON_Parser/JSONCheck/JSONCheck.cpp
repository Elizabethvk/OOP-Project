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
        // cout << "# " << key << " ";
    }

    // cout << endl;

    return key;
}

char JsonCheck::inputWhitespace(stringstream& fileStream) {
    char checkSymbol = fileStream.get();

    while (allWhitespace.find(checkSymbol) != string::npos) {
        checkSymbol = fileStream.get();
    }
    // TODO will it stay the same
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

bool JsonCheck::isItOperation(const char& ch) const {
    return ch == '+' || ch == '-';
}

char JsonCheck::whichOperation(const char& ch) {
    if (isItOperation(ch)) {
        return ch == '+' ? '+' : '-';
    }
    // Todo:What if not?
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
    case 'e':
        break;
    case 'E':
        break;
    case '-':
        symbolObjType = fileStream.get();
        return inputNumber(fileStream, symbolObjType);
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
            // cout << "#" << checkSymbol << " ";
    
    // if (checkSymbol != '{') {
    //     throw std::runtime_error("It should start with '{'");
    // }

    vector<string> userKeys;
    vector<JsonValue*> userValues;


    if (checkSymbol == '\"') {
            // cout << "#" << checkSymbol << " ";

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
            // cout << "#" << checkSymbol << " ";
        } while (checkSymbol == ',');

        if (isItWhitespace(checkSymbol)) {
            checkSymbol = inputWhitespace(fileStream);
        }

    }

    if (checkSymbol != '}') {
        throw std::runtime_error("Expected a '}' as a closing character of an object!");           
    }

    return new JsonObject(userKeys, userValues);
}

JsonValue* JsonCheck::inputNumber(stringstream& fileStream, char symbolObjType) {
    if (isItDigit(symbolObjType)) {
        double num = getNumber(fileStream, symbolObjType);
        return new JsonNumber(num);
    }
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

double JsonCheck::getNumber (stringstream& fileStream, char& ch) {
    stringstream getNumberStream;

    if (!isItDigit(ch) && isItOperation(ch)) {
        ch = fileStream.get();
        // TODO: throws, -'ses ...?
    }

    if (isItOperation(ch) || !isItDigit(ch)) {
        throw std::runtime_error("Too many operations e.g. ++/--");
    }

    do {
        if (ch == '.') {
            getNumberStream << ch;
            ch = fileStream.get();
            if (!isItDigit(ch)) {
                throw std::runtime_error("After '.' there should be one or more numbers!");
            }
            getNumberStream << ch;
            ch = fileStream.get();
            continue;
        }

        getNumberStream << ch;
        ch = fileStream.get();
    } while (isItDigit(ch) || ch == '.');

    if (ch != ',') {
        throw std::runtime_error("There must be ',' at the end!");
    }

    ch = fileStream.get();

    if (!isItWhitespace(ch)) {
        //TODO message
        throw std::runtime_error("");
    }

    inputWhitespace(fileStream);
    double number = 0;
    getNumberStream >> number;
    return number;


}

double JsonCheck::getNumberE (stringstream& fileStream, char& ch) {
    double numE = 2.72;

    if (ch != 'e'){
        throw std::runtime_error("Missing 'e' in the number!");
    }

    ch = fileStream.get();

    if(!isItOperation(ch) && isItDigit(ch)){
        double numWithE = getNumber(fileStream, ch);
        return numWithE * numE;
    }
    else if (!isItOperation(ch) && !isItDigit(ch)) {
        throw std::runtime_error("Missing an operation after an 'e'!");
    }

    char operation = whichOperation(ch);

    double temp = getNumber(fileStream, ch);

    return operation == '+' ? numE + temp : numE - temp;
}

void JsonCheck::checkJsonFile() {

}