
#include "SWord.h"

SWord::SWord(string word) {
    this->simple = word;
    vector<Word> words;
    this->allVersions = words;
}

SWord::SWord(string word, vector<Word> &allVersions) {
    this->simple = word;
    this->allVersions = allVersions;
}

int SWord::findWord(string &theWord) {
    int numVer = allVersions.size();
    for (int i = 0; i < numVer; i++) {
        Word currWord = allVersions.at(i);
        if (theWord == currWord.getKey()) {
            return i;
        }
    }
    return -1;
}


string SWord::getSimple() {
    return simple;
}

Word* SWord::getWord(string &theWord) {
    if (findWord(theWord) > -1) {
        return &allVersions.at(findWord(theWord));
    }
    return nullptr;
}


void SWord::addVersion(Word &word) {
    allVersions.push_back(word);
}

vector<Word>* SWord::getAllVersions() {
    return &allVersions;
}
