#ifndef __SWORD_H__
#define __SWORD_H__

#include <string>
#include <vector>

using namespace std;

class SWord {
public:
    
    SWord(string word);
    SWord(string word, vector<string> &allVersions);
    ~SWord();
    string getWord();
    vector<string> getAllVersions();
    void addVersion(string word);


private: 
    string simple;
    vector<string> allVersions;    
};


#endif