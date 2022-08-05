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
    Data tmpData; // making Data Struct
    string found = ""; // returns empty string if not exist
    if(id > 0){ // the id has to be greater than 0 to exist
        cout << "if id > 0 test line" << endl;
        int position = hash(id); // gets the key
        if (hashtable[position]->getNode(id, &tmpData)) { // get the node id and struct
            cout << "if key exists test line" << endl;
            found = tmpData.data; // if exists set found = to the struct string
        }
    }
    return found;
}

bool HashTable::removeEntry(int id){
    // pass in the id and return T/F for success or failure.
    bool flag = false;
    cout << "removeEntry test line" << endl;
    if (id > 0){  // input validation
        cout << "if id is greater than 0 test line " << endl;
        int position = hash(id); // gets the key
        if (hashtable[position]->deleteNode(id)) { // if the key exists
            cout << "if key exists test line " << endl;
            removed = true; // remove
            count -= 1;// decrement count
        }
    }
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

