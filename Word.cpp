#include "Word.h"
#include <iostream>
    
Word::Word(string word) {
    this->key = word;
}

Word::Word(string word, vector<pair<int,int> > index) {
    this->key = word;
    this->index = index;
}

string Word::getKey(){
    return key;
}
    

void Word::addInfo(pair <int, int> info) {
    index.push_back(info);
}

void Word::debugPrint() {
    cout << "Word: "<< key << endl;
    int size = index.size();
    for (int i=0; i<size; i++) {
        cout << "fileIndex: " << index.at(i).first << " lineNum: " << index.at(i).second << endl;
    }
}

vector<pair<int,int> >* Word::getIndex() {
    return &index;
}
