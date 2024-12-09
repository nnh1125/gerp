#ifndef GERP_H
#define GERP_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <list>
#include "Dictionary.h"
#include "DirNode.h"
#include "FSTree.h"
#include <utility>
#include <fstream>
#include <sstream>

using namespace std;

class gerp {
public:
    gerp();
    void run(string &inputDirectory, string &OutputFile);
    struct file {
	    string filePath;
	    vector <string> lines;
    };
    
private:
    string stripLowerCase(string &word);
    void insensitiveSearch(string &query, ofstream *output);
    void quit();
    void search(string &query, ofstream *output);
    void buildingIndex(string &directory);
    void readFile(gerp::file &currFile, int fileNum);
    void readLine(istream &input, int fileNum, int currLineNum);
    void readWord(int fileNum, int lineNum, string &theWord);
    void traverseDirectory(string &directory);
    void recursivelyTraverse(DirNode *node, string address);
    string stripNonAlphaNum(string &input);
    bool is_alphaNum(char c);

    Dictionary dict;

    vector <file> files;
    bool endGerp;
};

#endif