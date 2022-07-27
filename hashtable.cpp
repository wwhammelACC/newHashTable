/* 
Name: William Hammel
Hash Table
Purpose:  Create a Hash Table class/object
with our standard struct (a struct with an integer id
and a string for ‘data’). Implement a Separate Chaining
(i.e. not Linear Probing) hash table class.
 */

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
    flag = false;

    cout << "insertEntry test line" << endl;

    return flag;
}

string HashTable::getData(int id){

    cout << "getData test line" << endl;

    return found;
}

bool HashTable::removeEntry(int id){
    flag = false;

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
    return id % HASHTABLESIZE;
}

