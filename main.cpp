/* 
Name: William Hammel
Hash Table
Purpose:  Create a Hash Table class/object
with our standard struct (a struct with an integer id
and a string for ‘data’). Implement a Separate Chaining
(i.e. not Linear Probing) hash table class.
 */

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */


    //##########################################
    //INITIAL TESTING AND SET UP
    //##########################################

    cout << "******* INITIAL SET UP TESTING *****************************" << endl;
    // create your hash table object here
    cout << "creating the hash table..." << endl;
    HashTable *hashTab = new HashTable;
    cout << "done" << endl;
    cout << endl;

//    // show it is empty by calling getCount and printTable
//    cout << "testing initial printTable before insertEntry " << endl;
//    hashTab->printTable();
//    cout << "done" << endl;
//    cout << endl;
//    cout << "There are " << hashTab->getCount() << " entries in the table." << endl;
//    cout << endl;
//
//    // try and put ALL the test data into the table and show what happens
//    cout << "Inserting Test Data..." << endl;
//    for (int i = 0; i < testdatasize; i++) {
//        if (hashTab->insertEntry(ids[i], &strs[i])) {
//            cout << "success. entry inserted." << endl;
//            cout << "There are " << hashTab->getCount() << " entries in the table." << endl;
//        } else {
//            cout << "failed to insert entry: " << ids[i] << endl;
//            cout << endl;
//        }
//    }
//    cout << endl;
//
//    cout << "initial testing getData " << endl;
//    for (int i = 0; i < testdatasize; i++){
//        if(hashTab->getData(ids[i])!= ""){
//            cout << "found " << ids[i] << ": " << hashTab->getData(ids[i]) << endl;
//        }else{
//            cout << "empty string " << endl;
//        }
//    }
//    cout << endl;
//
//    cout << "testing printTable after insertEntry " << endl;
//    hashTab->printTable();
//    cout << "There are " << hashTab->getCount() << " entries in the table." << endl;
//    cout << "done" << endl;
//    cout << endl;
//
//    cout << "testing initial removeEntry " << endl;
//    cout << "Trying: " << ids[0] << "..." << endl;
//    if (hashTab->removeEntry(ids[0])) {
//        cout << "Success: " << ids[0] << " removed" << endl;
//    } else {
//        cout << "Failed: " << ids[0] << " was not found" << endl;
//    }
//    cout << endl;
//
//    cout << "initial testing printTable after removeEntry " << endl;
//    hashTab->printTable();
//    cout << "There are " << hashTab->getCount() << " entries in the table." << endl;
//    cout << "done" << endl;
//    cout << endl;
//
//    cout << "another initial removeEntry test " << endl;
//    cout << "Trying: " << ids[(int) (testdatasize - 1) / 2] << "..." << endl;
//    if(hashTab->removeEntry(ids[(int) (testdatasize - 1) / 2])){
//        cout << "Success: " << ids[(int) (testdatasize - 1) / 2] << " removed" << endl;
//    }else{
//        cout << "Failed: " << ids[(int) (testdatasize - 1) / 2] << " was not found" << endl;
//    }
//    cout << endl;
//
//    cout << "another initial testing printTable after removeEntry " << endl;
//    hashTab->printTable();
//    cout << "There are " << hashTab->getCount() << " entries in the table." << endl;
//    cout << "done" << endl;
//    cout << endl;
//
//    // Delete all, to start more in depth testing....
//    cout << "clearing table " << endl;
//    for (int i = 0; i < testdatasize; i++){
//        if (hashTab->removeEntry(ids[i])) {
//            cout << "Success: " << ids[i] << " removed" << endl;
//        } else {
//            cout << "Failed: " << ids[i] << " was not found" << endl;
//        }
//    }
//    cout << endl;
//
//    // show it is empty by calling getCount and printTable
//    cout << "Showing Table is empty before more in depth testing... " << endl;
//    hashTab->printTable();
//    cout << "done" << endl;
//    cout << endl;
//    cout << "There are " << hashTab->getCount() << " entries in the table." << endl;
//    cout << endl;



    // create your hash table object here
    
    // show it is empty by calling getCount and printTable
    
    // try and put ALL the test data into the table and show what happens

    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    
    
    
    
    return 0;
}
