#include "processing.h"

string stripNonAlphaNum(string input) {
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

bool is_alphaNum(char c) {
    if ((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') or 
    (c >= '0' and c <= '9')) {
        return true; 
    }
    return false;
}


void traverseDirectory(string directory) {
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
            cout << address << node->getFile(i) << endl;
        }       
    } 
    
}