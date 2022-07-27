/* 
Name: William Hammel
Hash Table
Purpose:  Create a Hash Table class/object
with our standard struct (a struct with an integer id
and a string for ‘data’). Implement a Separate Chaining
(i.e. not Linear Probing) hash table class.
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "linkedlist.h"
#include <iostream>
#include <string>

#define HASHTABLESIZE 15

using std::cout;
using std::endl;

class HashTable{

public:
    HashTable(); // constructor
    ~HashTable(); // destructor

    bool insertEntry(int, string*); // pass in the id and a string pointer and dynamically allocate inside the object
    string getData(int); // pass in the id and return the data string associated with that id.
    bool removeEntry(int); // pass in the id and return T/F for success or failure.
    int getCount(); // return the number of total entries currently in the hash table.
    void printTable(); // traverse the table showing all locations and their contents

private:

    int hash(int); //pass in the id and return id % HASHTABLESIZE
    int count;
    LinkedList *hashtable[HASHTABLESIZE];
};

#endif //HASHTABLE_H