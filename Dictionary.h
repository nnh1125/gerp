
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <list>
#include <utility>
#include "SWord.h"
#include "Word.h"

using namespace std;

class Dictionary {
public:
    Dictionary();
    SWord* getSWord(string &theWord);
    void insertSWord(string key, vector<Word> *allVersions);
    void insertWord(string &theWord, pair <int, int> info);
    void insertWord_helper(string &theWord, pair <int, int> info);
    void full();
    void expand();
    string stripLowerCase(string &org);
    
private:

    int currentTableSize;
    int numItemsInTable;
    vector < list<SWord> > table; 
    
};

#endif
