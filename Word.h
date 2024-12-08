#ifndef __WORD_H__
#define __WORD_H__

#include <string>
#include <vector>
#include <utility>

using namespace std;

class Word {
public:
    
    Word(string word);
    Word(string word, vector<pair<string,int>> index);
    ~Word();
    string getWord();
    vector<string> getAllVersions();
    void addIndex(string word);


private: 
    string word;
    vector<pair<string,int>> index;
};


#endif