/* 
Name: William Hammel
Hash Table
Purpose:  Create a Hash Table class/object
with our standard struct (a struct with an integer id
and a string for ‘data’). Implement a Separate Chaining
(i.e. not Linear Probing) hash table class.
 */

#ifndef HASHTABLES_H
#define HASHTABLES_H

#include "linkedlist.h"
#include <iostream>
#include <string>       /* string */

#define HASHTABLESIZE 15

using std::cout;
using std::endl;

class HashTable {

// public methods
public:

    HashTable(); // constructor
    ~HashTable(); // destructor

    bool insertEntry(int, string*);
    string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();

// private methods
private:

    int hash(int);
    int count;
    LinkedList *hashtable[HASHTABLESIZE];
};

#endif //HASHTABLES_H