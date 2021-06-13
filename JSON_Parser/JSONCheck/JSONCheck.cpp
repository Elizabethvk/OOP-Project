#include "JSONCheck.hpp"

#include <limits>
#include <cstring>

#include "../JSONStruct/JSONString.hpp"
#include "../JSONStruct/JSONNum.hpp"

#include "../ControlVariables/ControlVariables.hpp"



void JsonCheck::inputWhitespace(stringstream& fileStream) const {

	while (isItWhitespace(fileStream.peek())) {
		fileStream.get();
	}
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
	return ch == '+' ? '+' : '-';
}

bool JsonCheck::isInputLiteral(stringstream& fileStream, const string& str) const {
	
	if (str.length() == 5) {
		char temp[6];
		temp[5] = '\0';
		fileStream.read(temp, 5);
		return strcmp(temp, str.c_str()) == 0;
	}
	else {
		char temp[5];
		temp[4] = '\0';
		fileStream.read(temp, 4);
		return strcmp(temp, str.c_str()) == 0;
	}

}


double JsonCheck::getNumber(stringstream& fileStream, char& ch) const {
	stringstream getNumberStream;

	int dotCntr = -1;

	if (!isItDigit(ch) && isItOperation(ch)) {
		ch = fileStream.get();
	}

	double exponent = 1;


	if (!isItDigit(ch)) {
		cout << "ch3: " << ch << endl;
		throw UnknownValue();
	}

	do {
		if (ch == '.') {
			getNumberStream << ch;
			
			++dotCntr;

			if (dotCntr > 0) {
				throw std::runtime_error("Only one '.' is acceptable in a number!");
			}

			char nextSymbolCheck = fileStream.get();

			if (!isItDigit(nextSymbolCheck)) {
				throw std::runtime_error("Only digits are acceptable after a '.'!");
			}

			ch = fileStream.get();
			continue;
		}
		
		getNumberStream << ch;

		ch = fileStream.peek();

		if (ch == ',') {
			break;
		}
		else {
			if (ch == '}') {
				break;
			}
			ch = fileStream.get();
		}

	} while (isItDigit(ch) || ch == '.' || ch == '0');


	if (ch == 'e' || ch == 'E') {
		exponent = getNumberE(fileStream, ch);
	}


	inputWhitespace(fileStream);

	double number = 0;


	getNumberStream >> number;
	return pow(number, exponent);
}

double JsonCheck::getNumberE(stringstream& fileStream, char& ch) const {

	if (ch != 'e' && ch != 'E') {
		throw std::runtime_error("Missing 'e'/'E' in the number!");
	}

	ch = fileStream.get();

	double exponent = 0;

	if (isItOperation(ch)) {
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
		return pow(10, exponent);
	}
	else {
		throw std::runtime_error("Operation 'e'/'E' is followed by digits!");
	}
}


void JsonCheck::checkAnswer(int& answer) {
	while (answer != 1 && answer != 2 || !cin) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Choose an option between - 1 & 2" << endl;
		cin >> answer;
	}
}



int JsonCheck::stringToInt(const string& str) {
	unsigned int numberSize = str.length();
	int number = 0;

	for (unsigned int i = 0; i < numberSize; ++i) {
		if (str[i] != '[' && str[i] != ']') {
			number = number * 10 + str[i] - '0';
		}
	}

	return number;
}

vector<ControlVariables> JsonCheck::parsingCommand(const string& command) {
	unsigned int size = command.length();

	vector<ControlVariables> variables;

	string word;

	for (unsigned int i = 0; i < size; ++i) {
		if (i == size - 1 || command[i] == '.' || command[i] == '[' || command[i] == ']') {

			if (command[i] == ']') {
				word.push_back(command[i]);
				ControlVariables cntrlVars(word, stringToInt(word));
				variables.push_back(cntrlVars);
				word.clear();
				continue;
			}

			if (i == size - 1) {
				word.push_back(command[i]);
				ControlVariables cntrlVars(word, -1);
				variables.push_back(cntrlVars);
				word.clear();
				continue;
			}

			ControlVariables cntrlVars(word, -1);
			variables.push_back(cntrlVars);
			word.clear();

			if (command[i] == '.') {
				continue;
			}

		}
		word.push_back(command[i]);
	}

	return variables;
}


// Beginning of the main functionality



string JsonCheck::inputString(stringstream& fileStream) const {

	if (fileStream.get() != '\"') {
		throw std::runtime_error("Keys and values start with \'\"\' ");
	}

	char checkSymbol = fileStream.get();

	string key;

	while (checkSymbol != '\"') {
		key += checkSymbol;
		checkSymbol = fileStream.get();
	}

	return key;
}

JsonArray* JsonCheck::inputArray(stringstream& fileStream) const {
	char checkSymbol = fileStream.get();

	if (checkSymbol != '[') {
		throw NotAValidOpenArray();
	}

	inputWhitespace(fileStream);
	checkSymbol = fileStream.peek();

	if (checkSymbol == ']') {
		fileStream.get();
		return new JsonArray();
	}

	vector<JsonValue*> valuesArray;

	do {
		valuesArray.push_back(inputValue(fileStream));
		checkSymbol = fileStream.get();

	} while (checkSymbol == ',');

	if (checkSymbol != ']') {
		throw NotAValidCloseArray();
	}

	return new JsonArray(valuesArray);
}

JsonValue* JsonCheck::inputValue(stringstream& fileStream) const {
	inputWhitespace(fileStream);
	char symbolObjType = fileStream.peek();

	JsonValue* valueOfKey;
	string strValueOfKey = "";

	switch (symbolObjType)
	{
	case '{':
		valueOfKey = inputObject(fileStream);
		break;

	case '[':
		valueOfKey = inputArray(fileStream);
		break;

	case '\"':
		strValueOfKey = inputString(fileStream);
		valueOfKey = new JsonString(strValueOfKey);
		break;

	case 't':
		if (!isInputLiteral(fileStream, "true")) {
			throw NotAKeyWord();
		}
		valueOfKey = new JsonBool(true);
		break;
	case 'f':
		if (!isInputLiteral(fileStream, "false")) {
			throw NotAKeyWord();
		}
		valueOfKey = new JsonBool(false);
		break;

	case 'n':
		if (!isInputLiteral(fileStream, "null")) {
			throw NotAKeyWord();
		}
		valueOfKey = nullptr;
		break;

	case 'e':
		valueOfKey = inputNumber(fileStream);
		break;

	case 'E':
		valueOfKey = inputNumber(fileStream);
		break;

	case '0':
		valueOfKey = inputNumber(fileStream);
		break;

	case '-':
		valueOfKey = inputNumber(fileStream);
		break;

	default:
		if (isItDigit(symbolObjType)) {
			valueOfKey = inputNumber(fileStream);
		}
		else {

			throw InvalidValue();
		}
		break;
	}

	inputWhitespace(fileStream);

	return valueOfKey;
}

JsonObject* JsonCheck::inputObject(stringstream& fileStream) const {
	inputWhitespace(fileStream);

	char checkSymbol = fileStream.get();

	if (checkSymbol != '{') {
		throw std::runtime_error("It should start with '{'");
	}

	inputWhitespace(fileStream);
	checkSymbol = fileStream.peek();


	vector<string> userKeys;
	vector<JsonValue*> userValues;


	if (checkSymbol == '\"') {

		string key, value;

		do {
			inputWhitespace(fileStream);

			key = inputString(fileStream);
			inputWhitespace(fileStream);
			checkSymbol = fileStream.get();

			if (checkSymbol != ':') {
				throw std::runtime_error("Expected a : between the key and its value!");
			}

			checkSymbol = fileStream.get();
			userValues.push_back(inputValue(fileStream));
			// (*userValues.back()).print();

			userKeys.push_back(key);
			checkSymbol = fileStream.get();

		} while (checkSymbol == ',');

	}

	if (checkSymbol != '}') {
		throw std::runtime_error("Expected a '}' as a closing character of an object!");
	}

	return new JsonObject(userKeys, userValues);
}

JsonValue* JsonCheck::inputNumber(stringstream& fileStream) const {
	double number = 0;
	char symbolObjType = fileStream.get();

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

JsonValue* JsonCheck::inputJson(stringstream& fileStream) const {
	fileStream.seekg(0, std::ios::beg);
	inputWhitespace(fileStream);

	char checkSymbol = fileStream.peek();

	switch (checkSymbol)
	{
	case '{':
		return inputObject(fileStream);  
	case '[':
		return inputArray(fileStream);
	default:
		throw InvalidValue();
		break;
	}
}

// Begin of the public member functions

JsonCheck::JsonCheck()
	: isJsonLoaded(false)
{
}

JsonCheck::~JsonCheck()
{
	delete jsonFile;

}



void JsonCheck::openFile(const string& filePath) {
	string eachLine;

	if (isJsonLoaded) {
		cout << "A file is already opened!" << endl;
		return;
	}

	ifstream file;
	file.open(filePath, std::ios::in);

	if (!file.is_open()) {
		
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

		jsonFile = inputObject(fileStream);
		file.seekg(std::ios::beg);

		isJsonLoaded = true;
		cout << "The file data is loaded and ready to be used!" << endl;
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

void JsonCheck::create(const string& str, stringstream& fileStream) {

	if (fileStream.eof()) {
		cout << "No valid key and value!" << endl;
		return;
	}
	if (!isJsonLoaded) {
		cout << "There isn't an open file to use the create command!" << endl;
		return;
	}

	JsonValue* jsonValue;
	string key;
	char c = fileStream.get();
	while (c != ' ') {
		if (fileStream.eof()) {
			break;
		}
		if (c == '\"') {
			c = fileStream.get();
			continue;
		}
		key += c;
		c = fileStream.get();
	}

	inputWhitespace(fileStream);

	try
	{
		jsonValue = inputValue(fileStream);

	}
	catch (const std::exception& e) {
		cout << "Not a valid JSON Value!" << endl;
		return;
	}

	vector<ControlVariables> variables = parsingCommand(str);

	int cntr = variables.size() - 1;

	JsonObject* jsonObject = jsonFile;

	vector<ControlVariables>::iterator itVars;

	for (itVars = variables.begin(); itVars < variables.end(); ++itVars) {
		string key = (*itVars).getKey();
		// JsonValue* jsonValue;

		if (cntr == 0) {
			jsonObject->insertNewValue(key, jsonValue);
		}
		else {
			JsonValue* checkType = jsonObject->getValueByKey((*itVars).getKey());

			if (checkType->getType() == JSONOBJECT) {
				jsonObject = dynamic_cast<JsonObject*>(checkType);

				--cntr;
			}
		}

	}

	cout << "A value with key: " << str << " is created successfully!" << endl;
}


void JsonCheck::searchInFile(const string& str) const {
	if (!isJsonLoaded) {
		cout << "Json file haven't been opened! Nothing to search!";
		return;
	}

	cout << "Searching the value of the key: " << str << endl;
	jsonFile->keySearch(str);
	cout << endl;
}


void JsonCheck::edit(const string& str, stringstream& fileStream) {

	if (fileStream.eof()) {
		cout << "No valid key and value!" << endl;
		return;
	}
	if (!isJsonLoaded) {
		cout << "There isn't an open file to use the edit command!" << endl;
		return;
	}

	JsonValue* jsonValue;
	string key;
	char c = fileStream.get();
	while (c != ' ') {
		if (fileStream.eof()) {
			break;
		}
		if (c == '\"') {
			c = fileStream.get();
			continue;
		}
		key += c;
		c = fileStream.get();
	}
	//
	inputWhitespace(fileStream);

	try
	{
		jsonValue = inputValue(fileStream);
	}
	catch (const std::exception& e) {
		cout << "Problem in the format of the VALUE!" << endl;
		return;
	}

	jsonFile->keyChange(key, jsonValue);

	

	cout << "Changes are made successfully!\n";
}


void JsonCheck::removeByPath(const string& key) {
	if (!isJsonLoaded) {
		cout << "There isn't an open file to use the remove command!";
		return;
	}
	try {
		vector<ControlVariables> variables = parsingCommand(key);

		for (unsigned int i = 0; i < variables.size(); ++i) {
			cout << "Successfully removed " << key << " ." << endl;
			jsonFile->keySearch(key);
			cout << endl;
			jsonFile->removeByKey(variables[i].getKey());
		}
	}
	catch (const std::exception& e) {
		cout << e.what() << endl;
		return;
	}

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
	if (!isJsonLoaded) {
		cout << "No file is open to save the data to!";
		return;
	}

	ofstream file;
	file.open(fileName, std::ios_base::trunc | std::ios_base::out);

	if (!file.is_open()) {
		cout << "Something went wrong & the file cannot be opened!" << endl;
		return;
	}

	cout << "Saving the changes into the file!" << endl;
	jsonFile->save(file);

	cout << "Saved the file successfully!" << endl;
	file.close();
	isJsonLoaded = false;
	fileStream.clear();
}

void JsonCheck::saveAsFile(const string& newFileName) {
	if (!isJsonLoaded) {
		cout << "No file is open to save the data to!";
		return;
	}

	ofstream file;
	file.open(newFileName, std::ios_base::trunc | std::ios_base::out);

	if (!file.is_open()) {
		cout << "Something went wrong & the file cannot be opened!" << endl;
		return;
	}

	cout << "Saving the changes into the file!" << endl;
	// stringstream newFileData;
	jsonFile->save(file);

	cout << "Saved the file successfully!" << endl;
	file.close();
	isJsonLoaded = false;
	fileStream.clear();

}



void JsonCheck::terminateFunction() {
	int answer;
	cout << "There might be unsaved data!" << endl;
	cout << "If you want to exit without saving it type 1!" << endl;
	cout << "If you want to exit and saving it type 2!" << endl;

	cin >> answer;

	checkAnswer(answer);

	if (answer == 1) {
		throw Exit_Program();
	}
	else if (answer == 2) {
		cout << "If you want to save it to the same file write 1, if you want to save it to new file write 2!" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cin >> answer;

		checkAnswer(answer);

		if (answer == 1) {

			saveFile();
			throw Exit_Program();
		}
		else if (answer == 2) {
			cout << "Please input the path of the file!" << endl;
			string path;
			cin.ignore();
			getline(cin, path);
			saveAsFile(path);
			throw Exit_Program();
		}
	}
}


void JsonCheck::print() const {
	if (!isJsonLoaded) {
		cout << "Json file haven't been opened! Nothing to show!";
		return;
	}

	jsonFile->print();
}



void JsonCheck::help() const {
	cout << "You can choose from the following commands:" << endl;
	cout << "!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!" << endl;
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
	cout << "\t> edit <path> \"<string>\" " << endl;
	cout << "↓ To add a new json object by key <path> with value <string> ↓" << endl;
	cout << "\t> create <path> \"<string>\" " << endl;
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
	cout << "!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~!" << endl;

}

//
//void JsonCheck::move(const string& str, stringstream& fileStream)
//{
//	
//	string first, second;
//	char c = fileStream.get();
//	while (c != ' ') {
//		if (fileStream.eof()) {
//			break;
//		}
//		if (c == '\"') {
//			c = fileStream.get();
//			continue;
//		}
//		first += c;
//		c = fileStream.get();
//	}
//	//
//	
//	inputWhitespace(fileStream);
//	while (!fileStream.eof()) {
//		second += fileStream.get();
//	}
//
//	Plan: -> get first value (?) -> edit second with first vallue 
//	//jsonFile->
//	//jsonFile->keySearch(first);
//	//keyChange();
//
//	/*try
//	{
//		jsonValue = inputValue(fileStream);
//	}
//	catch (const std::exception& e) {
//		cout << "Problem in the format of the VALUE!" << endl;
//		return;
//	}*/
//
//}

