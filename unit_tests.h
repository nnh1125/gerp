#include "Dictionary.h"
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

// void insert() {
//     Dictionary dict;
//     // string key = "Hello";
//     string keys[8] = {"hello", "hellO", "h", "e", "l", "o", "hell", "lo"};
//     vector <string> value(11, "hello");
//     for (int i = 0; i < 8; i++) {
//         dict.insert(keys[i], value);
//     }
//     cout << dict.getNumItems() << endl;
//     cout << dict.getTableSize() << endl;
//     // assert(dict.getTableSize() == 20);
//     // assert(dict.getNumItems == 8);
// }


// void find() {
//     Dictionary dict;
//     // string key = "Hello";
//     string keys[8] = {"hello", "hellO", "h", "e", "l", "o", "hell", "lo"};
//     vector <string> value(11, "hello");
//     for (int i = 0; i < 8; i++) {
//         dict.insert(keys[i], value);
//     }
//     cout << dict.getNumItems() << endl;
//     cout << dict.getTableSize() << endl;
//     // assert(dict.getTableSize() == 20);
//     // assert(dict.getNumItems == 8);
//     cout << dict.find("h") << endl;
// }


void insert() {
    Dictionary dict;
    pair <int, int> info {1,2};
    string theWord = "hey";
    dict.insertWord(theWord, info);
    dict.getSWord(theWord)->getWord(theWord)->debugPrint();
}

void insertMoreIndex() {
    Dictionary dict;    
    string word = "testword";
    for(int i=0; i<10; i++) {
        pair<int,int> test(i,i+1);
        dict.insertWord(word, test);
    }
    dict.getSWord(word)->getWord(word)->debugPrint();

}

// void insertMoreWords() {
//     Dictionary dict;    
//     string word1 = "testWord";
//     string word2 = "good";
//     string word3 = "morning";
//     string word4 = "great";
//     string word5 = "bad";
//     string word6 = "sun";
//     string word7 = "many";
//     string word8 = "apple";
//     string word9 = "sure";
//     string word10 = "find";
//     string word11 = "never";
//     string word12 = "well";
//     string word13 = "test";
//     string word14 = "may";
//     string word15 = "after";
//     string word16 = "noon";
//     string word17 = "moon";
//     string word18 = "gg";
//     string word19 = "where";
//     string word20 = "a";
//     string word21 = "sometimes";
//     string word22 = "time";
//     string word23 = "june";
//     string word24 = "cool";
//     pair<int,int> test(1,2);
//     dict.insertWord(word1, test);
//     dict.insertWord(word2, test);
//     dict.insertWord(word3, test);
//     dict.insertWord(word4, test);
//     dict.insertWord(word5, test);
//     dict.insertWord(word6, test);
//     dict.insertWord(word7, test);
//     dict.insertWord(word8, test);
//     dict.insertWord(word9, test);
//     dict.insertWord(word10, test);
//     dict.insertWord(word11, test);
//     dict.insertWord(word12, test);
//     dict.insertWord(word13, test);
//     dict.insertWord(word14, test);
//     dict.insertWord(word15, test);
//     dict.insertWord(word16, test);
//     dict.insertWord(word17, test);
//     dict.insertWord(word18, test);
//     dict.insertWord(word19, test);
//     dict.insertWord(word20, test);
//     dict.insertWord(word21, test);
//     dict.insertWord(word22, test);
//     dict.insertWord(word23, test);
//     dict.insertWord(word24, test);

//     dict.getSWord(word1)->getWord(word1)->debugPrint();
//     dict.getSWord(word2)->getWord(word2)->debugPrint();
//     dict.getSWord(word3)->getWord(word3)->debugPrint();
//     dict.getSWord(word4)->getWord(word4)->debugPrint();
//     dict.getSWord(word5)->getWord(word5)->debugPrint();
//     dict.getSWord(word6)->getWord(word6)->debugPrint();
//     dict.getSWord(word7)->getWord(word7)->debugPrint();
//     dict.getSWord(word8)->getWord(word8)->debugPrint();
//     dict.getSWord(word9)->getWord(word9)->debugPrint();
//     dict.getSWord(word10)->getWord(word10)->debugPrint();
//     dict.getSWord(word11)->getWord(word11)->debugPrint();
//     dict.getSWord(word12)->getWord(word12)->debugPrint();
//     dict.getSWord(word13)->getWord(word13)->debugPrint();
//     dict.getSWord(word14)->getWord(word14)->debugPrint();
//     dict.getSWord(word15)->getWord(word15)->debugPrint();
//     dict.getSWord(word16)->getWord(word16)->debugPrint();
//     dict.getSWord(word17)->getWord(word17)->debugPrint();
//     dict.getSWord(word18)->getWord(word18)->debugPrint();
//     dict.getSWord(word19)->getWord(word19)->debugPrint();
//     dict.getSWord(word20)->getWord(word20)->debugPrint();
//     dict.getSWord(word21)->getWord(word21)->debugPrint();
//     dict.getSWord(word22)->getWord(word22)->debugPrint();
//     dict.getSWord(word23)->getWord(word23)->debugPrint();
//     dict.getSWord(word24)->getWord(word24)->debugPrint();
// }

void insertUpperCase() {
    Dictionary dict;    
    string word1 = "testWord";
    string word2 = "goOd";
    string word3 = "moRNing";
    string word4 = "great";
    string word5 = "bad";
    string word6 = "SuN";
    string word7 = "many";
    string word8 = "aPPle";
    string word9 = "SURE";
    string word10 = "find";

    string word11 = "testword";
    string word12 = "good";
    string word13 = "morning";
    string word14 = "great";
    string word15 = "bad";
    string word16 = "sun";
    string word17 = "many";
    string word18 = "apple";
    string word19 = "sure";
    string word20 = "find";

    pair<int,int> test(1,2);
    dict.insertWord(word1, test);
    dict.insertWord(word2, test);
    dict.insertWord(word3, test);
    dict.insertWord(word4, test);
    dict.insertWord(word5, test);
    dict.insertWord(word6, test);
    dict.insertWord(word7, test);
    dict.insertWord(word8, test);
    dict.insertWord(word9, test);
    dict.insertWord(word10, test);

    dict.getSWord(word11)->getWord(word1)->debugPrint();
    dict.getSWord(word12)->getWord(word2)->debugPrint();
    dict.getSWord(word13)->getWord(word3)->debugPrint();
    dict.getSWord(word14)->getWord(word4)->debugPrint();
    dict.getSWord(word15)->getWord(word5)->debugPrint();
    dict.getSWord(word16)->getWord(word6)->debugPrint();
    dict.getSWord(word17)->getWord(word7)->debugPrint();
    dict.getSWord(word18)->getWord(word8)->debugPrint();
    dict.getSWord(word19)->getWord(word9)->debugPrint();
    dict.getSWord(word20)->getWord(word10)->debugPrint();

}

void find() {
    Dictionary dict;
    pair <int, int> info {1,2};
    string theWord = "hey";
    dict.insertWord(theWord, info);
    cout << dict.getSWord("hey")->getSimple() << endl;
}