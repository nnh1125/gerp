#include "Dictionary.h"

/*
 * name:      Dictionary
 * purpose:   initialize a default constructor
 * arguments: none
 * returns:   none
 * effects:   initialize the currentTableSize and numItemsIntable
 */
Dictionary::Dictionary() {
    currentTableSize = 10; //initialize the table size
    numItemsInTable = 0;
    // init();
    table.resize(10);
}

void Dictionary::init() {
    list <SWord> nothing;
    for (int i = 0; i < currentTableSize; i++) {
        table.push_back(nothing);
    }
}

/*
 * name:      insertion
 * purpose:   insert a none stripped word
 * arguments: string key(the word)
 * returns:   none
 * effects:   insert a word
 */
void Dictionary::insertVersion(string word) {
    string key = stripNonAlphaNum(word);
    insert(key, word);
}

/*
 * name:      insertByWord
 * purpose:   insert a version of SWord
 * arguments: string key(the sWord) and the version of SWord
 * returns:   none
 * effects:   add a version to SWord
 */
void Dictionary::insertByWord(string key, string word) {
    hash <string> hashFunction; //use the built in hass function
    int slot = hashFunction(key) % currentTableSize; //hash
    
    list<string> *currList = &(table.at(slot));
    bool searchedForCollision = false;//to check if there is word in collision chain

    if(not currList->empty()) {
        int collisionSize = currList->size();
        for(list<string>::iterator it=currList->begin(); it != currList->end(); ++it) {
            if(word == it->getWord()) {
                searchedForCollision = true;
                currList->push_back(word);
                /* need to change this part to word struct */
            }   
        }
    }
    if((not searchedForCollision) or (currList->isEmpty())) {
        SWord currWord(key);//create a sWord instance
        currWord.addVersion(word);//add a version to it
        table.at(slot).push_back(currWord);//push it into the dictionary
        numItemsInTable++;//add numCount of the dictionary
        full(); //check the load factor
    }    
}

/*
 * name:      insertSWord 
 * purpose:   insert a SWord
 * arguments: string key(the sWord) and the vector of all of its versions
 * returns:   none
 * effects:   insert a SWord
 */
void Dictionary::insertSWord(string key, vector<string> &allVersions) {
    hash <string> hashFunction; //use the built in hass function
    int slot = hashFunction(key) % currentTableSize; //hash
    
        SWord currWord(key, allVersions);//create a sWord instance
        table.at(slot).push_back(currWord);//push it into the dictionary
        numItemsInTable++;//add numCount of the dictionary
        full(); //check the load factor
       
}

/*
 * name:      full
 * purpose:   to check if hashtable is overload
 * arguments: none
 * returns:   none
 * effects:   call expand function if hashtable is overload
 */
void Dictionary::full() {
    //calculate the load factor
    double loadFactor = (numItemsInTable *10)/ currentTableSize;
    // cout << to_string(loadFactor) << endl;
    if (loadFactor > 7) {
        cout << "fulled" << endl;
        expand(); //rehash if needed
    }
}

/*
 * name:      find
 * purpose:   find a word in the dictionary
 * arguments: string key(the sWord)
 * returns:   the slot of the word (-1 if not found)
 * effects:   return the slot of the word
 */
int Dictionary::find(string &word) {
    hash <string> hashFunction; //use the built in hass function
    int slot = hashFunction(word) % currentTableSize; //hash
    if (not (table.at(slot)).empty()) { //if that bucket is not empty
        list <SWord> curr = table.at(slot);
        //search through the list
        for (list<SWord>::iterator it=curr.begin(); it != curr.end(); ++it) {
            SWord currWord = *it;
            if (currWord->getWord() == word) { //if we found the word
                return slot;
            }
        }
        return -1; //we did not find the word
    }
    return -1;
}

/*
 * name:      expand 
 * purpose:   expand and insert the hashtable to twice of the original size
 * arguments: none
 * returns:   none
 * effects:   expand the hashtable
 */
void Dictionary::expand() {
    vector<list<SWord>> temp = table; //make a temporary table
    table.clear();
    numItemsInTable = 0;
    table.resize(2 * currentTableSize); //double the size of the org table
    int oldSize = currentTableSize;
    currentTableSize *= 2;
    // init();
    for (int i = 0; i < oldSize; i++) {  //loop through the temp table
        // cerr << "loop 1" << endl;
        list<SWord> *curr = &temp.at(i); //access the current SWord
        // int sWordSize = curr.size();
        // for (int j = 0; j < sWordSize; j++) {
        //     cerr << "loop 2" << endl; 
        //     sWord currWord = curr.at(j);
        //     insert(currWord.simple, currWord.allVersions);
        // }
        while (not curr->empty()) {
            SWord currWord = curr->front();
            curr->pop_front();

            insertSWord(currWord.getWord(), &currWord.getAllVersions());
        }
    }
}

// int Dictionary::getTableSize() {
//     return currentTableSize;
//     //return table.capacity();
// }

// int Dictionary::getNumItems() {
//     return numItemsInTable;
//     //return table.size();
// }

// void Dictionary::setFile(string &word) {
//     int slot = find(word);
//     word currWord = table.at(slot);
// }

// Dictionary::sWord* Dictionary::getSWord(string &word) { 
//     int slot = find(word);
//     return &table.at(slot);
// }

// file Dictionary::getFile(Word &word, string &fileName) {
//     for (set<file>::iterator it = word.files.begin(); it != word.files.end();
//         ++it) {
//             if ((*it).fileName == fileName) {
//                 return (*it);
//             }
//         }
// }

// void setline(string &word, int lineNum string &line) {
//     line curr = {lineNum, line};



//     int slot = find(word);
//     word currWord = table.at(slot);
// }

// void createLine(int lineNum, string &line) {
//     line curr = {lineNum, }
// }



Dictionary::~Dictionary() {

};

string Dictionary::stripNonAlphaNum(string input) {
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

bool Dictionary::is_alphaNum(char c) {
    if ((c >= 'A' and c <= 'Z') or (c >= 'a' and c <= 'z') or 
    (c >= '0' and c <= '9')) {
        return true; 
    }
    return false;
}