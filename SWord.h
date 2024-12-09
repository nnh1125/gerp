#ifndef __SWORD_H__
#define __SWORD_H__

#include <string>
#include <vector>
#include "Word.h"

using namespace std;

class SWord {
public:
    
    SWord(string word);
    SWord(string word, vector<Word> &allVersions);
    int findWord(string &theWord);
    Word* getWord(string &theWord);
    string getSimple();
    vector<Word> *getAllVersions();
    void addVersion(Word &theWord);


private: 
    string simple;
    vector<Word> allVersions;    
};


#endif
