#include "JSONCheck.hpp"

#include <limits>

#include "../JSONStruct/JSONString.hpp"
#include "../JSONStruct/JSONNum.hpp"

#include "../ControlVariables/ControlVariables.hpp"



char JsonCheck::inputWhitespace(stringstream& fileStream) const{
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
    return checkSymbol >= '0' && checkSymbol <= '9';
}


bool JsonCheck::isItOperation(const char& ch) const {
    return ch == '+' || ch == '-';
}

char JsonCheck::whichOperation(const char& ch) const {
    // if (isItOperation(ch)) {
        return ch == '+' ? '+' : '-';
    // }
    // Todo:What if not?
}

bool JsonCheck::inputLiteral(stringstream& fileStream, const string& str) const{
    char temp[str.size()];
    fileStream.read(temp, str.size());
    return str == temp;
}


double JsonCheck::getNumber (stringstream& fileStream, char& ch) const {
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
        // throw std::runtime_error("Unknown symbol in number!");
        throw UnknownValue();
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

double JsonCheck::getNumberE (stringstream& fileStream, char& ch) const {
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


void JsonCheck::checkAnswer(int& answer) {
    while (answer == 1 || answer == 2 || !cin) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout <<  "Choose an option between - 1 & 2" << endl;
        cin >> answer;
    }
}



int JsonCheck::stringToInt(const string& str) {
    unsigned int numberSize = str.length();
    int number = 0;

    for(unsigned int i = 0 ; i  < numberSize ; ++i){
        if(str[i] != '[' && str[i] != ']'){
            number = number * 10 + str[i] - '0';
        }
    }

    return number;
}

vector<ControlVariables> JsonCheck::parsingCommand (const string& command) {
    unsigned int size = command.length();

    vector<ControlVariables> variables;

    string word;

    for (unsigned int i = 0 ; i < size ; ++i){
        if (i == size - 1 || command[i] == '.' || command[i] == '[' ||command[i] ==']'){

            if(command[i] == ']'){
                word.push_back(command[i]);
                ControlVariables cntrlVars(word, stringToInt(word));
                variables.push_back(cntrlVars);
                word.clear();
                continue;
            }

            if(i == size - 1){
                word.push_back(command[i]);
                ControlVariables cntrlVars(word, -1);
                variables.push_back(cntrlVars);
                word.clear();
                continue;
            }

            ControlVariables cntrlVars(word,-1);
            variables.push_back(cntrlVars);
            word.clear();

            if (command[i] =='.') {
                continue;
            }

        }
        word.push_back(command[i]);
    }

    return variables;
}

// Begin of the main functionality



string JsonCheck::inputString(stringstream& fileStream, char checkSymbol) const {
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

JsonArray* JsonCheck::inputArray(stringstream& fileStream) const {
    char checkSymbol = fileStream.get();

    if (checkSymbol != '[') {
        // throw std::runtime_error("Arrays start with \'[\'");
        throw NotAValidOpenArray();
    }

    checkSymbol = inputWhitespace(fileStream);

    if (checkSymbol == ']') {
        fileStream.get();
        return new JsonArray();
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
        // throw std::runtime_error("The array should be closed with \']\'");
        throw NotAValidCloseArray();
    }

    return new JsonArray(valuesArray);
}

JsonValue* JsonCheck::inputValue(stringstream& fileStream, char symbolObjType) const {
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

JsonObject* JsonCheck::inputObject (stringstream& fileStream, char checkSymbol) const {
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

JsonValue* JsonCheck::inputNumber(stringstream& fileStream, char symbolObjType) const {
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

JsonValue* JsonCheck::inputJson (stringstream& fileStream) const {
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

// Begin of the public member functions


// JsonCheck::JsonCheck(const string& fileInfo) 
//     : fileName(fileInfo)
// {
// }



void JsonCheck::openFile(const string& filePath) {
    string eachLine;

    if (isJsonLoaded) {
        cout << "File is already opened!" << endl;
        return;
    }

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

        char firstSymbol = fileStream.get();
        firstSymbol = inputWhitespace(fileStream);
        jsonFile = inputObject(fileStream, firstSymbol);
        file.seekg(std::ios::beg);

        isJsonLoaded = true;
        cout << "The file data is loaded and ready to be used!" << endl;
        file.close();
    }

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
        cout << "It's not a valid JSON file!" << endl;
        return false;
    }

    cout << "This json file is valid & opened successfully!" << endl;
    fileStream.seekg(std::ios::beg);
    return true;
}

void JsonCheck::create (const string& str, stringstream& fileStream) {

}


void JsonCheck::searchInFile(const string& str) {
    if (!isJsonLoaded) {
        cout << "Json file haven't been opened! Nothing to search!";
        return;
    }

    cout << "Searching the value of the key: " << str << endl;
    jsonFile->keySearch(str);
    cout << endl;
    fileStream.seekg(0);

    // JsonValue* jsonValue = openCreate();
    // jsonValue->keySearch(str);
    // delete jsonValue;
    // TODO dynamic memory
}



void JsonCheck::edit(const string& str, stringstream& fileStream) {
    if(!isJsonLoaded){
        cout << "Please first open a JSON file before using the edit command !" << endl;
        return;
    }

    JsonValue* jsonValue;

    try
    {
        jsonValue = inputValue(fileStream, fileStream.get());
    }
    catch(const std::exception& e){
        cout << "Problem in the format of the VALUE!" << endl;
        return;
    }

    vector<ControlVariables> variables = parsingCommand(str);

    int counter = variables.size() - 1;

    JsonObject* jsonObject = jsonFile;

    for (auto & it : accessors) {
        if(jsonObject->checkKeyByString(it.getField())) {
            JsonValue* checkType = jsonObject->getSecondPropertyByKey(it.getField());
            if (checkType->getType() == JSONOBJECT) {
                if (it.getValue() == -1) {
                    JsonObject* setTypeObj = dynamic_cast<JsonObject *>(checkType);
                    if (counter == 0) {
                        setTypeObj->set(it.getField(), jsonValue);
                        return;
                    }
                    jsonObject = dynamic_cast<JsonObject*>(checkType);
                    counter--;
                    continue;
                }
            }
            //array not done !!!!!
            else if (checkType->getType() == JSONARRAY){
                JsonArray* setTypeArr = dynamic_cast<JsonArray*>(checkType);
                if (counter == 0){
                    setTypeArr->set(it.getValue(),jsonValue);
                    break;
                }
                counter--;
                continue;
            }
            else if (checkType->getType() == JSONSTRING){
                JsonString* setTypeStr  = dynamic_cast<JsonString*>(checkType);
                if(counter == 0){
                    string temp = jsonValue->getValueFromJsonString();
                    setTypeStr->set(temp);
                    break;
                }
                counter--;
                continue;
            }
            else if(checkType->getType() == JSONBOOLEAN){
                JsonBoolean* setTypeBool  = dynamic_cast<JsonBoolean*>(checkType);
                if(counter == 0){
                    setTypeBool->set(jsonValue->getValueFromJsonBoolean());
                    break;
                }
                counter--;
                continue;
            }
            else if(checkType->getType() == JSONNUMBER) {
                JsonNumber* setTypeNum = dynamic_cast<JsonNumber*>(checkType);
                if(counter == 0) {
                    setTypeNum->set(jsonValue->getValueFromJsonNumber());
                    break;
                }
                counter--;
                continue;
            }
        }
        else {
            cerr << "Not existing key !\n";
            return;
        }
    }
    cout << "Changes are made successfully!\n";


}



void JsonCheck::removeByPath(const string& key) {
    vector<ControlVariables> variables = parsingCommand(key);
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


void JsonCheck::saveFile() {
    if(!isJsonLoaded) {
        cout << "No file is open to save the data to!";
        return;
    }

    ofstream file;
    file.open(fileName, std::ios_base::trunc | std::ios_base::out);

    if(!file.is_open()) {
        cout << "Something went wrong & the file cannot be opened!" << endl;
        return;
    }

    cout << "Saving the changes into the file!" << endl;
    jsonFile->save(file);

    cout << "Saved the file successfully!" << endl;
    file.close();
}

void JsonCheck::saveAsFile(const string& newFileName) {
    if(!isJsonLoaded) {
        cout << "No file is open to save the data to!";
        return;
    }

    ofstream file;
    file.open(newFileName, std::ios_base::trunc | std::ios_base::out);

    if(!file.is_open()) {
        cout << "Something went wrong & the file cannot be opened!" << endl;
        return;
    }

    cout << "Saving the changes into the file!" << endl;
    // stringstream newFileData;
    jsonFile->save(file);

    cout << "Saved the file successfully!" << endl;
    file.close();
}



void JsonCheck::terminateFunction() {
    int answer;
    cout << "There might be unsaved data!" << endl;
    cout << "If you want to exit without saving it type 1!" << endl;
    cout << "If you want to exit and saving it type 2!" << endl;

    cin >> answer;
    
    checkAnswer(answer);

    if (answer == 1) {
        exit(0); // TODO
    }
    else if (answer == 2) {
        cout << "If you want to save it to the same file write 1, if you want to save it to new file write 2!" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> answer;

        checkAnswer(answer);

        if (answer == 1) {
            saveFile();
        }
        else if (answer == 2) {
            cout << "Please input the path of the file!" << endl;
            string path;
            getline(cin, path);
            saveAsFile(path);
        }
    }
}



// JsonValue* JsonCheck::openCreate() { //TODO
//     openFile(fileName);
//     return inputJson(fileStream);
// }


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


 void JsonCheck::print() const{
    if (!isJsonLoaded) {
        cout << "Json file haven't been opened! Nothing to show!";
        return;
    }

    // JsonValue* jsonValue = inputJson(fileStream);
    // jsonValue->print();
    jsonFile->print();
    // delete jsonValue;
}



void JsonCheck::help() const {
        cout << "You can choose from the following commands:" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "↓ To open a file ↓" << endl;
        cout << "\t> open <file>" << endl;
    cout << "↓ To close the file ↓" << endl;
        cout << "\t> close" << endl;
    cout << "↓ To save currently opened file ↓" << endl;
        cout << "\t> save" << endl;
    cout << "↓ To save currently opened file with in <file> ↓" << endl;
        cout << "\t> saveAs <file>" << endl;
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
    cout << "↓ To exit the program ↓" << endl;
        cout << "\t> exit" << endl;
    cout << "↓ To see the available commands again ↓" << endl;
        cout << "\t> help" << endl;
    cout << "------------------------------------------------------" << endl;

}









