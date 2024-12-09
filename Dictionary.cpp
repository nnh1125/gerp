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

// void Dictionary::init() {
//     list <SWord> nothing;
//     for (int i = 0; i < currentTableSize; i++) {
//         table.push_back(nothing);
//     }
// }


/*
 * name:      getSWord
 * purpose:   search among the dictionary to see if there is a SWord
 *            (simple version of the word)
 * arguments: string key(the sWord) and the version of SWord
 * returns:   none
 * effects:   add a version to SWord
 */
SWord* Dictionary::getSWord(string key) {
    // string key = stripLowerCase(theWord);
    hash <string> hashFunction; //use the built in hass function
    int slot = hashFunction(key) % currentTableSize; //hash for sword
    
    list<SWord> *currList = &(table.at(slot));//get to the collision list
    bool searchedForCollision = false;//to check if there is word in collision chain

    if(not currList->empty()) { //if there is collision
        for(list<SWord>::iterator it=currList->begin(); it != currList->end(); ++it) {
            if(key == it->getSimple()) { // if the sword is inserted
                searchedForCollision = true;
                return &(*it);
            }   
        }
    }

    if((not searchedForCollision) or (currList->empty())) {
        return nullptr;
    } 
    return nullptr;   
}

/*
 * name:      insertSWord 
 * purpose:   insert a SWord when resizing
 * arguments: string key(the sWord) and the vector of all of its versions
 * returns:   none
 * effects:   insert a SWord
 */
void Dictionary::insertSWord(string key, vector<Word> *allVersions) {
    hash <string> hashFunction; //use the built in hass function
    int slot = hashFunction(key) % currentTableSize; //hash
    
        SWord currWord(key, *allVersions);//create a sWord instance
        // SWord currWord(key);
        table.at(slot).push_back(currWord);//push it into the dictionary
        numItemsInTable++;//add numCount of the dictionary
        full(); //check the load factor
       
}

/*
 * name:      insertWord 
 * purpose:   insert a Word with its file index and lineNum
 * arguments: string key(the sWord) and the vector of all of its versions
 * returns:   none
 * effects:   insert a SWord
 */
void Dictionary::insertWord(string &theWord, pair <int, int> info) {
    string simple = stripLowerCase(theWord);
    //cout << "simple version: " << simple << endl;
    if (getSWord(simple) == nullptr) {
        //cerr << "getword failed" << endl;
        vector <Word> allVersions;
        insertSWord(simple, &allVersions);
    } 
    insertWord_helper(theWord, simple, info);
}

void Dictionary::insertWord_helper(string &theWord, string simple, pair <int, int> info) {
    if (getSWord(simple)->findWord(theWord) > -1) {
            //cerr << "branch 1" << endl;
            Word *currWord = getSWord(simple)->getWord(theWord);
            currWord->addInfo(info);
    } else {
            //cerr << "branch 2" << endl;
            vector< pair<int,int> > index;
            Word currWord(theWord, index);
            currWord.addInfo(info);
            getSWord(simple)->addVersion(currWord);
            
            
    }
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
 * name:      expand 
 * purpose:   expand and insert the hashtable to twice of the original size
 * arguments: none
 * returns:   none
 * effects:   expand the hashtable
 */
void Dictionary::expand() {
    vector< list<SWord> > temp = table; //make a temporary table
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
            SWord currSWord = curr->front();
            curr->pop_front();

            insertSWord(currSWord.getSimple(), currSWord.getAllVersions());
        }
    }
}


string Dictionary::stripLowerCase(string &org) {
    int wordSize = org.size();
    string lower = "";
    for (int i = 0; i < wordSize; i++) {
        char c = tolower(org[i]);
        lower += c;
    }
    return lower;
}
