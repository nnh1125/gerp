
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <list>
#include "SWord.h"

using namespace std;

class Dictionary {
public:
    Dictionary();
    ~Dictionary();
    void insertVersion(string key);
    void insertByWord(string key, string word);
    void insertSWord(string key, vector <string> &allVersions);
    void full();
    int find(string &word);
    int getTableSize();
    int getNumItems();
    void set();
private:
    // struct sWord {
    //     string simple;
    //     // vector <word> allVersions;
    //     vector <string> allVersions;
    // };

    // struct word {
	//     string key;
	//     set <file> files;
    // }

    // struct file {
	//     string fileName;
	//     set <line> lines;
    // }

    // struct line {
	//     int lineNum;
	//     string lineContent;
    // }


    int currentTableSize;
    int numItemsInTable;
    
    vector <list<SWord>> table;
    
    void expand();
    void init();
    string stripNonAlphaNum(string input);
    bool is_alphaNum(char c);
};

#endif