#ifndef GERP_H
#define GERP_H

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <list>
#include "Dictionary.h"

using namespace std;

class Gerp {
public:
    
private:
    string stripLowerCase(string &word);
    void readFile(string &filename);
    void readLine(string &line);
    void readword(string &word);


    struct file {
	    string filePath;
	    vector <string> lines;
    };

    vector <file> files;
    bool end;
};

#endif