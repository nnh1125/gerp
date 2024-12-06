
// #include "processing.h"

#include "Dictionary.h"

using namespace std;

int main(int argc, char *argv[]) {
    // string test = "@##!!#!@!#COMP-15!!!!!!!";
    // // string test = "cat@";
    // // string test = "@!";
    // cout << stripNonAlphaNum(test) << endl;
    // string directory = argv[1];
    // traverseDirectory(directory);
    // return 0;
    string key = "";
    string word = "";
    Dictionary dict;
    for (int i = 0; i < 20; i++) {
        key += "a";
        word += "b";
        dict.insertByWord(key, word);
    }
    return 0;
}
