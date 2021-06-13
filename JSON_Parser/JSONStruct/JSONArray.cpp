#include "JSONArray.hpp"

int JsonArray::openBracketsCounterArr = 0;

JsonArray::JsonArray() 
{
    type = JSONARRAY;
}


JsonArray::JsonArray(const vector<JsonValue*>& values) 
    : values(values)
{
    type = JSONARRAY;
}

Type JsonArray::getType() const {
    return type;
}

void JsonArray::edit(const int& valueNr, JsonValue* value) {
    bool isFound = false;

    unsigned int sizeArr = values.size();
    for (unsigned int i = 0; i < sizeArr; ++i) {
        if (i == valueNr) {
            values[i] = value;
            isFound = true;
        }
    }

    if (!isFound) {
        throw std::runtime_error("Couldn't find the desired value!");
    }
} 


void JsonArray::save(ofstream& userFile) const {
    userFile << "[" << endl;

    ++openBracketsCounterArr;

    unsigned int sizeArr = values.size();
    for (unsigned int i = 0; i < sizeArr; ++i) {
        values[i]->save(userFile);

        if (i <= sizeArr-2) {
            userFile << ", ";
        }
    }

    --openBracketsCounterArr;

    if (openBracketsCounterArr != 0) {
        userFile << " ]," << endl;
    }
    else {
        userFile << " ]";
    }
}


void JsonArray::print() const{
    cout << "[" << endl;

    ++openBracketsCounterArr;

    unsigned int sizeArr = values.size();
    for (unsigned int i = 0; i < sizeArr; ++i) {
        values[i]->print();

        if (i <= sizeArr-2) {
            cout << ", ";
        }
    }

    --openBracketsCounterArr;

    if (openBracketsCounterArr != 0) {
        cout << " ]," << endl;
    }
    else {
        cout << " ]";
    }
}