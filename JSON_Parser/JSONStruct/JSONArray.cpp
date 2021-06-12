#include "JSONArray.hpp"

JsonArray::JsonArray() 
{
    type = JSONARRAY;
}

JsonArray::JsonArray(const vector<JsonValue*>& values) 
    : values(values)
{
    type = JSONARRAY;
}

vector<JsonValue*> JsonArray::getValues() const {
    return values;
}


Type JsonArray::getType() const {
    return type;
}

void JsonArray::edit(const int& valueNr, JsonValue* value) {
    unsigned int sizeArr = values.size();
    for (unsigned int i = 0; i < sizeArr; ++i) {
        if (i == valueNr) {
            values[i] = value;
        }
    }
} 

void JsonArray::save(ofstream& userFile) {
    // printValue(userFile);

    userFile << "[ ";

    unsigned int sizeArr = values.size();
    for (unsigned int i = 0; i < sizeArr; ++i) {
        values[i]->save(userFile);
        if (i <= values.size()-2) {
            userFile << ", ";
        }
    }


    // printArrElements();

    userFile << " ]";
} //TODO fix print const n stuff

void JsonArray::keySearch(const string& key) const {

}

void JsonArray::printArrElements() const {
    unsigned int sizeArr = values.size();
    for (unsigned int i = 0; i < sizeArr; ++i) {
        values[i]->printValue();
        if (i <= values.size()-2) {
            cout << ", ";
        }
    }
}

void JsonArray::printValue(std::ostream& out) {
    out << "[ ";

    unsigned int sizeArr = values.size();
    for (unsigned int i = 0; i < sizeArr; ++i) {
        values[i]->save(out);
        if (i <= values.size()-2) {
            out << ", ";
        }
    }


    // printArrElements();

    out << " ]";
    // cout << endl;

    // vector<JsonValue*>::iterator itValues;
    // for (itValues = values.begin(); itValues < values.size(), ++itValues) {
    // }

}

void JsonArray::print() {
    // printValue(cout);
    cout << "[" << endl;
    unsigned int sizeArr = values.size();
    for (unsigned int i = 0; i < sizeArr; ++i) {
        values[i]->print();
        if (i <= sizeArr-2) {
            cout << ", ";
        }
    }


    // // printArrElements();

    cout << "]" << endl;
}