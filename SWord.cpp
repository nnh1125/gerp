
#include "SWord.h"

SWord::SWord(string word) {
    this->simple = word;
}

SWord::SWord(string word, vector<string> &allVersions) {
    this->simple = word;
    this->allVersions = allVersions;
}

string SWord::getWord() {
    return simple;
}

void SWord::addVersion(string word) {
    allVersions.push_back(word);
}

vector<string> SWord::getAllVersions() {
    return allVersions;
}