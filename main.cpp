
// #include "processing.h"

#include "gerp.h"

using namespace std;

// int main() {
//     // string test = "@##!!#!@!#COMP-15!!!!!!!";
//     // // string test = "cat@";
//     // // string test = "@!";
//     // cout << stripNonAlphaNum(test) << endl;
//     // string directory = argv[1];
//     // traverseDirectory(directory);
//     // return 0;
//     // Dictionary dict;    
//     // for(int i=0; i<10; i++) {
//     //     pair<int,int> test(i,i+1);
//     //     string word = "testWord";
//     //     dict.insertWord(word, test);
//     // }
//     // return 0;
//     gerp the_gerp;

// }

int main(int argc, char *argv[]) {
    gerp the_gerp;
    string inputDirectory = argv[1];
    string outputFile = argv[2];
    the_gerp.run(inputDirectory, outputFile);
    return 0;
}
