#include "Dictionary.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

void insert() {
    Dictionary dict;
    // string key = "Hello";
    string keys[8] = {"hello", "hellO", "h", "e", "l", "o", "hell", "lo"};
    vector <string> value(11, "hello");
    for (int i = 0; i < 8; i++) {
        dict.insert(keys[i], value);
    }
    cout << dict.getNumItems() << endl;
    cout << dict.getTableSize() << endl;
    // assert(dict.getTableSize() == 20);
    // assert(dict.getNumItems == 8);
}


void find() {
    Dictionary dict;
    // string key = "Hello";
    string keys[8] = {"hello", "hellO", "h", "e", "l", "o", "hell", "lo"};
    vector <string> value(11, "hello");
    for (int i = 0; i < 8; i++) {
        dict.insert(keys[i], value);
    }
    cout << dict.getNumItems() << endl;
    cout << dict.getTableSize() << endl;
    // assert(dict.getTableSize() == 20);
    // assert(dict.getNumItems == 8);
    cout << dict.find("h") << endl;
}