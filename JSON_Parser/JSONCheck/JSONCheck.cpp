#include "JSONCheck.hpp"

#include "../JSONStruct/JSONString.hpp"
#include "../JSONStruct/JSONNum.hpp"

JsonCheck::JsonCheck(const string& fileInfo) 
    : fileName(fileInfo)
{
}

void JsonCheck::openFile(const string& filePath) {
    string eachLine;

    ifstream file;
    file.open(filePath, std::ios::in);

    if (!file.is_open()) {
        // couldnt open file with this name
        // throw std::
        // TODO custom except
        isJsonLoaded = false;
        cout << "Creating new empty file with name: " << filePath << endl;
        ofstream openNewFile;
        openNewFile.open(filePath, std::ios::out);

        if (!openNewFile.is_open()) {
            isJsonLoaded = false;
            throw std::runtime_error("Error creating new file! Please reopen the program!");
        }
        openNewFile.close();
        return;
    }
    else {
        fileName = filePath;

        while (getline(file, eachLine)) {
            fileStream << eachLine;
        }

        isJsonLoaded = true;
        cout << "The file data is loaded and ready to be used!" << endl;
        file.close();
    }

}

JsonValue* JsonCheck::openCreate() {
    openFile(fileName);
    return inputJson(fileStream);
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

// JsonBool* JsonCheck::keyWords(stringstream& fileStream, char symbolObjType) {
//     // char nextLetter = 0;
//     // bool isRight = 0;
//     switch (symbolObjType)
//     {
//         case 't':
//         //TODO: fix
//             if (!inputLiteral(fileStream, "true")) {
//                 throw std::runtime_error("The value should have been \"true\"");
//             }
//             else {
//                 return JsonBool(true);
//             }
//             break;
//         case 'f':
//             if (!inputLiteral(fileStream, "false")) {
//                 throw std::runtime_error("The value should have been \"false\"");
//             }
//             else {
//                 return JsonBool(false);
//             }
//             break;
//         case 'n':
//             if (!inputLiteral(fileStream, "null")) {
//                 throw std::runtime_error("The value should have been \"nul\"");
//             }
//             else {
//                 return nullptr;
//             }
//             break;
//     }
//     return isRight;
// }

bool JsonCheck::inputLiteral(stringstream& fileStream, const string& str) {
    char temp[str.size()];
    fileStream.read(temp, str.size());
    return str == temp;
}

bool JsonCheck::isItOperation(const char& ch) const {
    return ch == '+' || ch == '-';
}

char JsonCheck::whichOperation(const char& ch) {
    // if (isItOperation(ch)) {
        return ch == '+' ? '+' : '-';
    // }
    // Todo:What if not?
}

 
string JsonCheck::inputString(stringstream& fileStream, char checkSymbol) {
    // char checkSymbol = fileStream.get();
    // cout << "Chek: " <<  checkSymbol << endl;
    
    // if (fileStream.get() != '\"'){
    if (checkSymbol != '\"'){
        throw std::runtime_error("Keys and values start with \'\"\' ");
    }
    // vector<char> key;
    // cout << "here" << endl;

    checkSymbol = fileStream.get();
    string key;
    while (checkSymbol != '\"') {
        key += checkSymbol;
        checkSymbol = fileStream.get();
        // cout << "#str: " << key << " ";
    }

    // cout << endl;
    // cout << key << endl;
    return key;
}

JsonArray* JsonCheck::inputArray(stringstream& fileStream) {
    char checkSymbol = fileStream.get();

    if (checkSymbol != '[') {
        throw std::runtime_error("Arrays start with \'[\'");
    }

    checkSymbol = inputWhitespace(fileStream);

    if (checkSymbol == ']') {
        fileStream.get();
        return new JsonArray;
    }

    vector<JsonValue*> valuesArray;

    // if (checkSymbol == ' ') {
    //     checkSymbol = inputWhitespace(fileStream);
    // }

    // do {
    //     if (checkSymbol == ',') {
    //         checkSymbol = inputWhitespace(fileStream);
    //     }
    do {
        valuesArray.push_back(inputValue(fileStream, checkSymbol));
        checkSymbol = fileStream.get();

    } while (checkSymbol == ',');

    // if (isItWhitespace(checkSymbol)) {
    //     checkSymbol = inputWhitespace(fileStream);
    // }
    // TODO: up
    
    if (checkSymbol != ']') {
        throw std::runtime_error("The array should be closed with \']\'");
    }

    return new JsonArray(valuesArray);
}

JsonValue* JsonCheck::inputValue(stringstream& fileStream, char symbolObjType) {
    // double number = 0;

    symbolObjType = inputWhitespace(fileStream);
    JsonValue* valueOfKey;
    string strValueOfKey = "";

    switch (symbolObjType)
    {
    case '{':
        // return inputObject(fileStream);
        valueOfKey = inputObject(fileStream, symbolObjType);
        break;
    case '[':
        valueOfKey = inputArray(fileStream);
        break;
    case '\"':
        strValueOfKey = inputString(fileStream, symbolObjType);
        valueOfKey = new JsonString(strValueOfKey);
        break;
    case 't':
    //TODO: fix
        if (!inputLiteral(fileStream, "true")) {
            throw std::runtime_error("The value should have been \"true\"");
        }
        else {
            valueOfKey = new JsonBool(true);
        }
        break;
    case 'f':
        if (!inputLiteral(fileStream, "false")) {
            throw std::runtime_error("The value should have been \"false\"");
        }
        else {
            valueOfKey = new JsonBool(false);
        }
        break;
    case 'n':
        if (!inputLiteral(fileStream, "null")) {
            throw std::runtime_error("The value should have been \"nul\"");
        }
        else {
            valueOfKey = nullptr;
        }
        break;
    case 'e':
        valueOfKey = inputNumber(fileStream, symbolObjType);
        break;
    case 'E':
        valueOfKey = inputNumber(fileStream, symbolObjType);
        break;
    case '0':
        valueOfKey = inputNumber(fileStream, symbolObjType);
        break;
    case '-':
        valueOfKey = inputNumber(fileStream, symbolObjType);
    case '+':
        valueOfKey = inputNumber(fileStream, symbolObjType);
    default:
        if (isItDigit(symbolObjType)) {
            valueOfKey = inputNumber(fileStream, symbolObjType);
        }
        else {
            cout << "Default: " << symbolObjType << endl;
            throw std::runtime_error("Unknown value!");
        }
        break;
        // throw std::runtime_error("Unknown value!");
        // break;
    }

    symbolObjType = inputWhitespace(fileStream);
    return valueOfKey;
}

JsonObject* JsonCheck::inputObject (stringstream& fileStream, char checkSymbol) {
    // checkSymbol = inputWhitespace(fileStream);
            // cout << "#" << checkSymbol << " "; //TODO remove
    
    if (checkSymbol != '{') {
        throw std::runtime_error("It should start with '{'");
    }

    checkSymbol = inputWhitespace(fileStream);
            cout << "#" << checkSymbol << " "; //TODO remove

    vector<string> userKeys;
    vector<JsonValue*> userValues;


    if (checkSymbol == '\"') {
            // cout << "#" << checkSymbol << " ";
            // cout << "Ye" << endl;

        string key, value;
        
        do {
            // if (checkSymbol == ',') {
            //     checkSymbol = inputWhitespace(fileStream);
            //     if (checkSymbol != '\"') {
            //         throw std::runtime_error("Not a valid JSON object! Each key starts and ends with \" \" ");
            //     }
            // }

            // checkSymbol = inputWhitespace(fileStream);
            // cout << "#" << checkSymbol << " ";

            key = inputString(fileStream, checkSymbol);
            cout << "K: " << key << endl;

            checkSymbol = inputWhitespace(fileStream);

            if (checkSymbol != ':') {
                // cout << "throw: " << checkSymbol << endl;
                throw std::runtime_error("Expected a : between the key and its value!");
            }
            
            checkSymbol = inputWhitespace(fileStream);

            userValues.push_back(inputValue(fileStream, checkSymbol));
            userKeys.push_back(key);
            checkSymbol = fileStream.get();
            // cout << "#" << checkSymbol << " ";
        } while (checkSymbol == ',');

        // if (isItWhitespace(checkSymbol)) {
        //     checkSymbol = inputWhitespace(fileStream);
        // }

    }

    if (checkSymbol != '}') {
        throw std::runtime_error("Expected a '}' as a closing character of an object!");           
    }

    return new JsonObject(userKeys, userValues);
}

JsonValue* JsonCheck::inputNumber(stringstream& fileStream, char symbolObjType) {
    double number = 0;
    
    if (isItDigit(symbolObjType)) {
        number = getNumber(fileStream, symbolObjType);
        return new JsonNumber(number);
    }
    else if (symbolObjType == '-') {
        symbolObjType = fileStream.get();
        number = (-1) * getNumberE(fileStream, symbolObjType);
        return new JsonNumber(number);
    }
    else if (symbolObjType == 'e' || symbolObjType == 'E') {
        number = getNumberE(fileStream, symbolObjType);
        return new JsonNumber(number);
    }
    else {
        return nullptr;
    }
}

JsonValue* JsonCheck::inputJson (stringstream& fileStream) {
    char checkSymbol = inputWhitespace(fileStream);
    switch (checkSymbol)
    {
    case '{' :
        cout << "*** " << checkSymbol << endl;
        return inputObject(fileStream, checkSymbol);    
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
    // string numbStr;
    int dotCntr = -1;
    // cout << "ch1: " << ch << endl;


    if (!isItDigit(ch) && isItOperation(ch)) {
        // cout << "in" << endl;
        ch = fileStream.get();
        // cout << "ch2: " << ch << endl;

        // TODO: throws, -'ses ...?
    }

    // if (isItOperation(ch) || !isItDigit(ch)) {
    //     throw std::runtime_error("Too many operations e.g. ++/--");
    // }
    double exponent = 1;
    
    // if (ch == 'e' || ch == 'E') {
    //     cout << "e" << endl;
    //     exponent = getNumberE(fileStream, ch);
    //     cout << "ex " << exponent << endl; 
    // }


    if (!isItDigit(ch)) {
        cout << "ch3: " << ch << endl;
        throw std::runtime_error("Unknown symbol in number!");
    }

    do {
        if (ch == '.') {
            // numbStr += ch;
            getNumberStream << ch;
            // ch = fileStream.get();
            // if (!isItDigit(ch)) {
            //     throw std::runtime_error("After '.' there should be one or more numbers!");
            // }
            ++dotCntr;

            if (dotCntr > 0) {
                throw std::runtime_error("Only one '.' is acceptable in a number!");
            } 

            char nextSymbolCheck = fileStream.get();
            if (!isItDigit(nextSymbolCheck)) {
                throw std::runtime_error("Only digits are acceptable after a '.'!");
            }

            // getNumberStream << ch;
            ch = fileStream.get();
            continue;
        }
        // cout << "ChN: " << ch << endl;
        // numbStr = numbStr + ch;
        // cout << "Str: " << numbStr << endl;
        getNumberStream << ch;

        // ch = fileStream.get();
        // cout << "ChN: -" << ch << endl;

        if (ch == ',') {
            break;
            // throw std::runtime_error("There must be ',' at the end!");
        }
        else {
            ch = fileStream.get();
        }

    } while (isItDigit(ch) || ch == '.' || ch == '0'); // TODO == '0'???


    ch = fileStream.get();

    
    if (ch == 'e' || ch == 'E') {
        exponent = getNumberE(fileStream, ch);
    }
    
    // if (!isItWhitespace(ch)) {
    //     //TODO message
    //     throw std::runtime_error("");
    // }
    
    // cout << getNumberStream.str() << endl;

    ch = inputWhitespace(fileStream);
    double number = 0;

    // double nrFStr = stoi(numbStr);
    // cout << "Stoi: " << nrFStr << endl;

    getNumberStream >> number;
    // cout << "Numb: " << number << endl;
    return pow(number, exponent);
}

double JsonCheck::getNumberE (stringstream& fileStream, char& ch) {
    // double numE = 2.72;

    if (ch != 'e' && ch != 'E'){
        throw std::runtime_error("Missing 'e'/'E' in the number!");
    }

    ch = fileStream.get();
    double exponent = 0;

    // if(!isItOperation(ch) && isItDigit(ch)){
    //     double numWithE = getNumber(fileStream, ch);
    //     return numWithE * numE;
    // }
    // else if (!isItOperation(ch) && !isItDigit(ch)) {
    //     throw std::runtime_error("Missing an operation after an 'e'!");
    // }
    // cout << "Ch: " << ch << endl;

    if (isItOperation(ch)) {
        // char operation = whichOperation(ch);
        switch (ch)
        {
        case '-':
            ch = fileStream.get();
            exponent = getNumber(fileStream, ch);
            return pow(10, -exponent);
            // break;
        case '+':
            ch = fileStream.get();
            exponent = getNumber(fileStream, ch);
            return pow(10, exponent);

        default:
            throw std::runtime_error("Operation is followed by digits!");
            break;
        }
    }
    else if (isItDigit(ch)) {
        exponent = getNumber(fileStream, ch);
        // cout << "pow: " << pow(10, exponent) << endl;
        return pow(10, exponent);
    }
    else {
        throw std::runtime_error("Operation 'e'/'E' is followed by digits!");
    }
    // double temp = getNumber(fileStream, ch);
    // return operation == '+' ? numE + temp : numE - temp;
}

void JsonCheck::help() {
        cout << "You can choose from the following commands:" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "↓ To open a file ↓" << endl;
        cout << "\t> open <file>" << endl;
    cout << "↓ To close the file ↓" << endl;
        cout << "\t> close" << endl;
    cout << "↓ To save currently opened file ↓" << endl;
        cout << "\t> save" << endl;
    cout << "↓ To save currently opened file with in <file> ↓" << endl;
        cout << "\t> saveas <file>" << endl;
    cout << "↓ To validate if the file is in a valid JSON format ↓" << endl;
        cout << "\t> validate" << endl;
    cout << "↓ To search the file by <key> ↓" << endl;
        cout << "\t> search <key>" << endl;
    cout << "↓ To change the value of <path> to <string> ↓" << endl;
        cout << "\t> edit <path> <string>" << endl;
    cout << "↓ To add a new json object by key <path> with value <string> ↓" << endl;
        cout << "\t> create <path> <string>" << endl;
    cout << "↓ To remove an element <path> ↓" << endl;
        cout << "\t> remove <path>" << endl;
    cout << "↓ To move an element from its place <from> to the place of another element <to> ↓" << endl;
        cout << "\t> move <from> <to>" << endl;
    cout << "↓ To print the file ↓" << endl;
        cout << "\t> print" << endl;
    cout << "↓ To see the available commands again ↓" << endl;
        cout << "\t> help" << endl;
    cout << "------------------------------------------------------" << endl;

}


bool JsonCheck::checkJsonFile() {
    if (!isJsonLoaded) {
        cout << "Json file haven't been loaded! Nothing to check!";
        return false;
    }
    try {
        inputJson(fileStream);
    }
    catch (const std::exception& e) {
        cout << e.what() << endl;
        return false;
    }

    cout << "This json file is valid & opened successfully!" << endl;
    return true;
}

void JsonCheck::closeFile() {
    if (!isJsonLoaded) {
        cout << "There isn't an open file to close!";
        return;
    }
    
    cout << "The file is closed successfully! File: " << fileName << endl;
    fileName.clear();
    fileStream.clear();
    isJsonLoaded = false;
}  

void JsonCheck::searchInFile(const string& str) {
    if (!isJsonLoaded) {
        cout << "Json file haven't been opened! Nothing to search!";
        return;
    }

    JsonValue* jsonValue = openCreate();
    jsonValue->keySearch(str);
    delete jsonValue;
    // TODO dynamic memory
}

void JsonCheck::print() {
    if (!isJsonLoaded) {
        cout << "Json file haven't been opened! Nothing to show!";
        return;
    }

    JsonValue* jsonValue = inputJson(fileStream);
    jsonValue->print();
    delete jsonValue;
}