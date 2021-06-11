#include "JSONObject.hpp"

void JsonObject::addSpace(const unsigned int n) const {
    for(unsigned int i = 0; i < n; ++i) {
        cout << " ";
    }
}

JsonObject::JsonObject() {
    type = JSONOBJECT;
}

JsonObject::JsonObject(const vector<string>& keys, const vector<JsonValue*>& values) 
    : keys(keys), values(values)
{
    type = JSONOBJECT;
}



// vector<string> JsonObject::getKeys() const {
//     return keys;
// }

// vector<JsonValue*> JsonObject::getJsonValues() const {
//     return values;
// }

// template<typename Base, typename T>
// inline bool instanceof(const T*) {
//    return isBaseOf<Base, T>::value;
// }
//    Child *c;
//    if(instanceof<Child>(c)) {
//       cout << "c is instance of Child class" << endl;
//    } else {
//       cout << "c is not instance of Child class" << endl;
//    }
//    if(instanceof<Parent>(c)) {
//       cout << "c is instance of Parent class" << endl;
//    } else {
//       cout << "c is not instance of Parent class" << endl;
//    }
//    if(instanceof<AnotherClass>(c)) {
//       cout << "c is instance of AnotherClass class" << endl;
//    } else {
//       cout << "c is not instance of AnotherClass class" << endl;
//    }
// int JsonObject::isItValue(const string& name) const {
//     switch (name)
//     {
//     case :
//         /* code */
//         break;
    
//     default:
//         break;
//     }
// }

Type JsonObject::getType() const {
    return type;
}

JsonValue* JsonObject::getByKey(const string& key) const {
    for (unsigned int i = 0; i < keys.size(); ++i) {
        if (key == keys[i]) {
            return values[i];
        }
    }

    throw std::runtime_error("Couldn't find the key to change the value!");

}

void JsonObject::edit(const string& str, JsonValue*& value) {
    
    for (unsigned int i = 0; i < keys.size(); ++i) {
        if (str == keys[i]) {
            values[i] = value;
        }
    }

    throw std::runtime_error("Couldn't find the key to change the value!");
}

bool JsonObject::checkByStringKey(const string& str) const {
    for (unsigned int i = 0; i < keys.size(); ++i) {
        if (str == values[i]->getJsonStringValue()) {
            return true;
        }
    }

    return false;
}

void JsonObject::keySearch(const string& str) const {
    int foundAt = -1;

    for (unsigned int i = 0; i < keys.size(); ++i) {
        if (str == keys[i]) {
            // foundAt = i;
            values[i]->print();
            return;
        }
        else if (values[i]->getType() == JSONOBJECT) {
            values[i]->keySearch(str);
            break;
        }

    }

    // if (foundAt != -1) {
    //     values[foundAt]->printValue();
    // }
    // else {
    //     throw std::runtime_error("Couldn't find a value for this key!");
    // }
}

// void JsonObject::printValue() const {
//     cout << "{" << endl;

//     unsigned int sizeVect = keys.size();
//     for (unsigned int i = 0; i < sizeVect; ++i ) {
//         cout << " \"" << keys[i] << "\": \" ";
//         values[i]->printValue();
//         if (i <= sizeVect-2) {
//             cout << ", " << endl;
//         }
//     }

//     cout << "}" << endl;
// }

void JsonObject::save(ofstream& userFile) const {
    printValue(userFile);
}

void JsonObject::printValue(std::ostream& out) const {
    cout << "{" << endl;

    unsigned int sizeVect = keys.size();
    for (unsigned int i = 0; i < sizeVect; ++i ) {
        addSpace(SPACE_TO_PRINT);

        cout << " \"" << keys[i] << "\": \" ";
        values[i]->printValue();
        if (i <= sizeVect-2) {
            cout << ", " << endl;
        }
    }

    cout << endl;
    addSpace(SPACE_TO_PRINT);
    cout << "}" << endl;
}

void JsonObject::print() const{
    printValue(cout);
    // cout << "{" << endl;

    // unsigned int sizeVect = keys.size();
    // for (unsigned int i = 0; i < sizeVect; ++i ) {
    //     addSpace(SPACE_TO_PRINT);

    //     cout << " \"" << keys[i] << "\": \" ";
    //     values[i]->printValue();
    //     if (i <= sizeVect-2) {
    //         cout << ", " << endl;
    //     }
    // }

    // cout << endl;
    // addSpace(SPACE_TO_PRINT);
    // cout << "}" << endl;
    //========
    // cout << "{" << endl;
    // unsigned int sizeVect = keys.size();
    
    // for (unsigned int i = 0; i < sizeVect; ++i ) {
    //     cout << "\"" << keys[i] << "\": \"" << "\"" << values[i] << "\"" << endl;
    // }
    // printValue();
    //TODO: look it
    // cout << "}" << endl;
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