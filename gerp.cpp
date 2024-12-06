#include "gerp.h"

Gerp::Gerp {
    Dictionary dict;
    end = false;
}

void gerp::run(string &inputDirectory, &stringOutputFile) {
    buildingIndex(directory);
    string query;
    while (not end) {
        cout << "Query? ";
        cin >> query;
        if (query == "@i" or query == "@insensitive") {
            cin >> query;
            insensitiveSearch(query);
        } else if (query == "")

    }
}

void gerp::buildingIndex(string &directory) {
    traverseDirectory(directory);
    int totalFiles = files.size();
    for (int i = 0; i < totalFiles; i++) {
        readFile(files.at(i), i);
    }
}

void gerp::readFile(file &currFile, int fileNum) {
    ifstream infile(currFile.filePath);
    if (infile.fail()) { //TODO: change error message
        throw runtime_error("Unable to open file " + filename);
    }
    string lineContent;
    getline (infile, lineContent);
    int currLineNum = 1;
    while (not infile.eof()) {
        currFile.lines.push_back(lineContent);
        istringstream iss(lineContent);
        readLine(iss, fileNum, currLineNum);
    }
    infile.close();
}

void gerp::readLine(istream &input, int &fileNum, int &currLineNum) {
    string currWord;
    while (input >> currWord) {
        readWord(fileNum, currLineNum, currWord);
    }
}

void traverseDirectory(string &directory) {
    FSTree tree(directory);
    DirNode* root = tree.getRoot();
    recursivelyTraverse(root, "");
}

void recursivelyTraverse(DirNode *node, string address) {
    address += node->getName() + "/";
    
    if(node->hasSubDir()) {
        for(int i = 0; i < node->numSubDirs(); i++) {  
            recursivelyTraverse(node->getSubDir(i), address);
        }
    }

    if(node->hasFiles()) {
        for(int i = 0; i < node->numFiles(); i++) {
            // cout << address << node->getFile(i) << endl;
            address += node->getFile(i);
            files.push_back(file {address, vector <int> lineNums});
        }       
    } 
    
}

void readWord(int &fileNum, int &lineNum, string &theWord) {
    pair <int,int> info (fileNum, lineNum);
    word currWord = {theWord, info};
    //TODO:insert the word to the dictionary
}