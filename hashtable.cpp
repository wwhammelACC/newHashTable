/* 
Name: William Hammel
Hash Table
Purpose:  Create a Hash Table class/object
with our standard struct (a struct with an integer id
and a string for ‘data’). Implement a Separate Chaining
(i.e. not Linear Probing) hash table class.
 */

#include "hashtable.h"

/*
 * ****************************************
 * Constructors / Destructors
 * ****************************************
 */

//constructor
HashTable::HashTable() {
    count = 0;
    for(int i = 0; i < HASHTABLESIZE; i++){
        hashtable[i] = new LinkedList;
    }
}

//destructor
HashTable::~HashTable() {
    for (int i = 0; i < HASHTABLESIZE; i++) {
        if (hashtable[i]) {
            delete hashtable[i];
        }
    }
}

/*
 * ****************************************
 * Public
 * ****************************************
 */


bool HashTable::insertEntry(int id, string *info){
    bool flag = false;

    cout << "insertEntry test line" << endl;

    if(id > 0 && *info != "\0" ){
        int position = hash(id);
        // linked list named hashtable send id/info to it's addNode
        // note here linked lists addNode inserts data
        cout << "if test insert entry " << endl;
        if(hashtable[position]->addNode(id, info)){
            cout << "send to addNode in linked list test " << endl;
            flag = true;
            count++;
        }
    }
    return flag;
}

string HashTable::getData(int id){
    //making temporary data holder for testing
//    Data tmpData;
//    string found = "";
//    if(id > 0){
//        int position = hash(id);
//        if (hashtable[position]->getNode(id, &tmpData)) {
//            found = tmpData.data;
//        }
//    }
    string found = "";
    cout << "getData test line" << endl;
    return found;
}

bool HashTable::removeEntry(int id){
    bool flag = false;

    cout << "removeEntry test line" << endl;

    return flag;
}

int HashTable::getCount(){
    // count is internal and updated within insertEntry
    cout << "getCount test line" << endl;
    return count;
}

void HashTable::printTable(){
    cout << "printTable test line" << endl;
}

/*
 * ****************************************
 * Private
 * ****************************************
 */

int HashTable::hash(int id){
    return id % HASHTABLESIZE; //pass in the id and return id % HASHTABLESIZE, creates the key
}

