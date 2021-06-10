#include "JSONArray.hpp"

JsonArray::JsonArray() 
{
}

JsonArray::JsonArray(const vector<JsonValue*>& values) 
    : values(values)
{
}

vector<JsonValue*> JsonArray::getValues() const {
    return values;
}


void JsonArray::keySearch(const string& key) const {

}

void JsonArray::printArrElements() const {
    for (unsigned int i = 0; i < values.size(); ++i) {
        values[i]->printValue();
        if (i <= values.size()-2) {
            cout << ", ";
        }
    }
}

void JsonArray::printValue() const {
    cout << "[ ";

    printArrElements();

    cout << " ]";
    // cout << endl;

    // vector<JsonValue*>::iterator itValues;
    // for (itValues = values.begin(); itValues < values.size(), ++itValues) {
    // }

}

void JsonArray::print() const {
    cout << "[" << endl;
    
    printArrElements();

    cout << "]" << endl;
}