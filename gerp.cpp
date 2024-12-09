#include "gerp.h"

/*
 * name:      gerp
 * purpose:   default constructor
 * arguments:
 * returns:   none
 * effects:   
 */
gerp::gerp() {
    endGerp = false;
}

/*
 * name:      run
 * purpose:   command loop run the program
 * arguments: an input stream
 * returns:   none
 * effects:   read the input from the input stream
 */
void gerp::run(string &inputDirectory, string &OutputFile) {
    ofstream output;
    output.open(OutputFile);
    buildingIndex(inputDirectory);
    string query;
    while (not (endGerp or cin.eof())) {
        cout << "Query? ";
        cin >> query;
        if (query == "@i" or query == "@insensitive") {
            cin >> query;
            query = stripNonAlphaNum(query);
            insensitiveSearch(query, &output);
        } else if (query == "@q" or query == "quit") {
            quit();
        } else if (query == "@f") {
            output.close();
            cin >> OutputFile;
            output.open(OutputFile);
        } else {
            query = stripNonAlphaNum(query);
            search(query, &output);
        }
    }
    output.close();
}

void gerp::insensitiveSearch(string &query, ofstream *output) {
    string lowerCase = stripNonAlphaNum(query);
    if (dict.getSWord(lowerCase) == nullptr) {
        *output << "query Not Found." << endl;
        return;
    } 
    SWord *currSWord = dict.getSWord(lowerCase);
    vector <Word> *versions = currSWord->getAllVersions();
    int numVersions = versions->size();
    for (int j = 0; j < numVersions; j++) {
        Word *theWord = &versions->at(j);
        vector <pair<int,int> >* index = theWord->getIndex();
        int indexSize = index->size();
        for (int i = 0; i < indexSize; i++) {
            int fileNum = index->at(i).first;
            int lineNum = index->at(i).second;
            file currFile = files.at(fileNum);
            *output << currFile.filePath << ":" << to_string(lineNum);
            *output << ": " << currFile.lines.at(lineNum) << endl;
        }
    }

}

/*
 * name:      quit
 * purpose:   exit the program
 * arguments: none
 * returns:   none
 * effects:   print out the exit message and quit the command loop
 */
void gerp::quit() {
    cout << "Goodbye! Thank you and have a nice day." << endl;
    endGerp = true;
}

/*
 * name:      stripNonAlphaNum
 * purpose:   strip the string, removes all leading and trailing 
 *            non-alphanumeric characters.
 * arguments: a string to strip
 * returns:   a stripped string 
 * effects:   
 */
string gerp::stripNonAlphaNum(string &input) {
    int start = 0;
    int end = input.size();
    while (start < input.size() and not(is_alphaNum(input[start]))) {
        ++start;
    }
    while (end > start and not(is_alphaNum(input[end - 1]))) {
        --end;
    }
    return input.substr(start, end - start);
}

bool gerp::is_alphaNum(char c) {
    if ((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') or 
    (c >= '0' and c <= '9')) {
        return true; 
    }
    return false;
}

// void gerp::sensitive(string &query, ofstream *output) {
    
// }

/*
 * name:      search
 * purpose:   search for the word in the query, output the result in the output
 *            file
 * arguments: string query and a pointer to ouput stream
 * returns:   none
 * effects:   
 */
void gerp::search(string &query, ofstream *output) {
    string strippedWord = stripNonAlphaNum(query);
    if (dict.getSWord(strippedWord) == nullptr) {
        *output << "query Not Found. Try with @insensitive or @i." << endl;
        return;
    } 
    Word *theWord = dict.getSWord(strippedWord)->getWord(strippedWord);
    vector <pair<int,int> >* index = theWord->getIndex();
    int indexSize = index->size();
    for (int i = 0; i < indexSize; i++) {
        int fileNum = index->at(i).first;
        int lineNum = index->at(i).second;
        file currFile = files.at(fileNum);
        *output << currFile.filePath << ":" << to_string(lineNum);
        *output << ": " << currFile.lines.at(lineNum - 1) << endl;
    }
}

/*
 * name:      buildingIndex
 * purpose:   building the file index for a provided directory
 * arguments: string dirirectory name
 * returns:   none
 * effects:   
 */
void gerp::buildingIndex(string &directory) {
    traverseDirectory(directory);
    int totalFiles = files.size();
    for (int i = 0; i < totalFiles; i++) {
        readFile(files.at(i), i);
    }
}

/*
 * name:      readFile
 * purpose:   read a file, store all its content in the data stucture
 * arguments: the currentFile, the file number
 * returns:   none
 * effects:   
 */
void gerp::readFile(gerp::file &currFile, int fileNum) {
    ifstream infile(currFile.filePath);
    // if (infile.fail()) { //TODO: change error message
    //     throw runtime_error("Unable to open file " + filename);
    // }
    string lineContent;
    int currLineNum = 1;
    while (getline (infile, lineContent)) {
        currFile.lines.push_back(lineContent);
        istringstream iss(lineContent);
        readLine(iss, fileNum, currLineNum);
        currLineNum++;
    }
    infile.close();
}

/*
 * name:      readLine
 * purpose:   read a line in a file
 * arguments: input stream, file number, line number
 * returns:   none
 * effects:   
 */
void gerp::readLine(istream &input, int fileNum, int currLineNum) {
    string currWord;
    while (input >> currWord) {
        readWord(fileNum, currLineNum, currWord);
    }
}


void gerp::traverseDirectory(string &directory) {
    FSTree tree(directory);
    DirNode* root = tree.getRoot();
    recursivelyTraverse(root, "");
}

void gerp::recursivelyTraverse(DirNode *node, string address) {
    address += node->getName() + "/";
    
    if(node->hasSubDir()) {
        for(int i = 0; i < node->numSubDirs(); i++) {  
            recursivelyTraverse(node->getSubDir(i), address);
        }
    }

    if(node->hasFiles()) {
        for(int i = 0; i < node->numFiles(); i++) {
            // cout << address << node->getFile(i) << endl;
            string filePath = address + node->getFile(i);
            vector <string> lines;
            files.push_back(file {filePath, lines});
        }       
    } 
    
}

/*
 * name:      readWord
 * purpose:   insert a word into the data structure
 * arguments: file number, line number, and string word
 * returns:   none
 * effects:   
 */
void gerp::readWord(int fileNum, int lineNum, string &theWord) {
    pair <int,int> info (fileNum, lineNum);
    // word currWord = {theWord, info};
    dict.insertWord(theWord, info);
}

string gerp::stripLowerCase(string &org) {
    int wordSize = org.size();
    string lower = "";
    for (int i = 0; i < wordSize; i++) {
        char c = tolower(org[i]);
        lower += c;
    }
    return lower;
}