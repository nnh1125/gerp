#ifndef __WORD_H__
#define __WORD_H__

#include <string>
#include <vector>
#include <utility>

using namespace std;

class Word {
public:
    
    Word(string word);
    Word(string word, vector<pair<int,int> >index);
    void addInfo(pair <int,int> info);
    string getKey();
    void debugPrint();
    vector<pair<int,int> >* getIndex();


private: 
    string key;
    vector<pair<int,int> > index;
};


#endif
