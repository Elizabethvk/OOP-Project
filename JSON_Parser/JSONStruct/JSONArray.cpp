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

void JsonArray::print() const {
    cout << "[" << endl;

    for (unsigned int i = 0; i < values.size(); ++i) {
        values[i]->print();
    }

    cout << "]" << endl;
}