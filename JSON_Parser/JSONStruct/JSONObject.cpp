#include "JSONObject.hpp"

int JsonObject::openBracketsCounter = 0;

string JsonObject::addSpace(const unsigned int n) const {
    string space;
    
    for(unsigned int i = 0; i < n; ++i) {
        space.push_back(' ');
    }

    return space;
}

JsonObject::JsonObject() {
    type = JSONOBJECT;
}

JsonObject::JsonObject(const vector<string>& keys, const vector<JsonValue*>& values) 
    : keys(keys), values(values)
{
    type = JSONOBJECT;
}


Type JsonObject::getType() const {
    return type;
}

JsonValue* JsonObject::getValueByKey(const string& key) const {
    for (unsigned int i = 0; i < keys.size(); ++i) {
        if (key == keys[i]) {
            return values[i];
        }
    }

    throw std::runtime_error("Couldn't find the key to change the value!");

}

void JsonObject::insertNewValue(const string& key, JsonValue* value) {
    keys.push_back(key);
    values.push_back(value);
}


void JsonObject::keySearch(const string& key) const {
    int foundAt = -1;

    for (unsigned int i = 0; i < keys.size(); ++i) {
        if (key == keys[i]) {
            foundAt = i;
            cout << "The value of the key is ";
            values[i]->print();
            return;
        }
        else if (values[i]->getType() == JSONOBJECT) {
            values[i]->keySearch(key);
            break;
        }

    }

    if (foundAt == -1) {
        cout << "Couldn't find this key: " << key << endl;
        return;
    }
}


void JsonObject::edit(const string& key, JsonValue*& value) {
    bool hasSomethingChanged = false;

    for (unsigned int i = 0; i < keys.size(); ++i) {
        if (key == keys[i]) {
            values[i] = value;
            hasSomethingChanged = true;
        }
    }
    
    if (!hasSomethingChanged) {
        throw std::runtime_error("Couldn't find the key to change the value!");
    }
}


bool JsonObject::doKeyAndValueMatch(const string& key) const {
    for (unsigned int i = 0; i < keys.size(); ++i) {
        if (key == keys[i]) {
            return true;
        }
    }

    return false;
}

void JsonObject::removeByKey(const string& key) {
    bool isFound = false;
    for (unsigned int i = 0; i < keys.size(); ++i) {
        if (key == keys[i]) {
            keys.erase(keys.begin(), keys.begin() + i);
            isFound = true;
        }
    }

    if (!isFound) {
        throw std::runtime_error("Couldn't find the key to remove the value!");
    }
}

void JsonObject::save(ofstream& userFile) const {
    userFile << "{" << endl;

    ++openBracketsCounter; // Countint in static because there might be object inside of objects

    unsigned int sizeVect = keys.size();

    for (unsigned int i = 0; i < sizeVect; ++i ) {
        userFile << addSpace(SPACE_TO_PRINT);

        userFile << " \"" << keys[i] << "\": ";

        values[i]->save(userFile);

        if (i <= sizeVect-2) {
            userFile << ", " << endl;
        }
    }

    --openBracketsCounter;

    if (openBracketsCounter != 0) {
        userFile << endl;
        userFile << addSpace(SPACE_TO_PRINT);
        userFile << "}" << endl;
    }
    else {
        userFile << endl;
        userFile << "}" << endl;
    }
}

void JsonObject::print() const {
    cout << "{" << endl;

    ++openBracketsCounter; // Countint in static because there might be object inside of objects

    unsigned int sizeVect = keys.size();

    for (unsigned int i = 0; i < sizeVect; ++i ) {
        cout << addSpace(SPACE_TO_PRINT);

        cout << " \"" << keys[i] << "\": \" ";

        values[i]->print();

        if (i <= sizeVect-2) {
            cout << ", " << endl;
        }
    }

    --openBracketsCounter;

    if (openBracketsCounter != 0) {
        cout << endl;
        cout << addSpace(SPACE_TO_PRINT);
        cout << "}" << endl;
    }
    else {
        cout <<endl<< "}" << endl;
    }
}
