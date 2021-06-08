#include "JSONObject.hpp"

JsonObject::JsonObject(const vector<string>& keys, const vector<JsonValue*>& values) 
    : keys(keys), values(values)
{
}

vector<string> JsonObject::getKeys() const {
    return keys;
}

vector<JsonValue*> JsonObject::getJsonValues() const {
    return values;
}

void JsonObject::print() const{
    cout << "{" << endl;
    unsigned int sizeVect = keys.size();
    
    for (unsigned int i = 0; i < sizeVect; ++i ) {
        cout << "\"" << keys[i] << "\": \"" << "\"" << values[i] << "\"" << endl;
    }

    cout << "}" << endl;
}

/*
void JsonObject::print() const{
    cout << "{" << endl;
    unsigned int sizeVect = keys.size();
    
    for (unsigned int i = 0; i < sizeVect; ++i ) {
        cout << "\"" << keys[i] << "\": \"" << "\"" << *values[i] << "\"";
    }

    cout << endl << "}" << endl;
}

*/