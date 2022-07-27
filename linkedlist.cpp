/*********************
Name: William Hammel
Coding 06: Hash Tables
Purpose:  In this assignment you will create a
Hash Table class/object (as discussed in class)
with our standard struct (a struct with an integer id
and a string for ‘data’).
**********************/

#include "linkedlist.h"

/*
 * ****************************************
 * Constructors / Destructors
 * ****************************************
 */


//constructor
LinkedList::LinkedList() {

    head = NULL;
}

//desctructor
LinkedList::~LinkedList() {
    clearList();
}

/*
 * ****************************************
 * Public
 * ****************************************
 */

//Trying Different addNode Version
bool LinkedList::addNode(int id, string *info) {
    bool flag = false;
    if (id > 0 && *info != "/0") {
        Node **nodeHold;
        cout << endl;
        if (head == NULL || id < head->data.id) {
            addHead(id, info, head, *nodeHold);
            flag = true;
        }else{
            cout << endl;
            Node *current = head;
            while (id > current->data.id && current->next != NULL) {
                current = current->next;
            }
            if (id == current->data.id) {
                flag = false;
            } else if (id > current->data.id && current->next == NULL) {
                addTail(id, info, current, *nodeHold);
                flag = true;
            } else {
                addMiddle(id, info, current, *nodeHold);
                flag = true;
            }
        }
    }
    return flag;
}

bool LinkedList::deleteNode(int id) {
    bool flag = false;
    Node *current = head;
    if (id > 0 ) {
        if (head == NULL) {
            flag = false;
        } else {
            while (id != current->data.id && current->next != NULL){
                current = current->next;
            }
            if (id != current->data.id) {
                flag = false;
            }else if(id == current->data.id && current->prev == NULL && current->next == NULL){
                delete(current);
                head = NULL;
                flag = true;
            }else if(current->prev == NULL){
                current->next->prev = NULL;
                head = current->next;
                delete (current); //Deallocate
                flag = true;
            }else if(current->next == NULL){
                current->prev->next = NULL;
                delete (current); //Deallocate
                flag = true;
            }else if(id == current->data.id){
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete (current); //Deallocate
                flag = true;
            }
        }
    }
    return flag;
}

bool LinkedList::getNode(int id, Data *info) {
        bool flag = false;
    if (head != NULL) {
        Node *current = head;
        while (id != current->data.id && current->next != NULL) {
            current = current->next;
        }
        if (id == current->data.id) {
            info->data = current->data.data; // data is the string
            info->id = current->data.id;     // this is the int id
            flag = true;
        }
        else {
            info->data = "";
            info->id = -1;
            flag = false;
        }
    }
    return flag;
}

void LinkedList::printList(bool direction) {
    //bool flag = true;
    Node *current = head;
    if (direction == false) {    //traverse forward
        int i = 1;
        if (current == NULL) {
            cout << "Empty " << endl;
        } else {
            while (current != NULL) {
                cout << current->data.id << " : " << current->data.data << "->";
                current = current->next; // go to the next node
                i++;
            }
            cout << "\b\b  ";
            cout << endl;
        }
    } else {
        current = head; // start a "tracking" pointer by pointing it head
        int i = 1;
        bool tail = false;
        while (current && !tail) { // find the tail
            if (current->next) {
                current = current->next;
            } else {
                tail = true; // found the tail
            }
        }
        // now traverse it backward
        if (current == NULL) {
            cout << "Empty " << endl;
        }else{
            while (current) {
                cout << current->data.id << " : " << current->data.data <<"->";
                current = current->prev;
                i++;
            }
            cout << "\b\b  ";
            cout << endl;
        }
    }
    cout << endl;
}

int LinkedList::getCount() {
    int count = 0;
    Node *current = head;
    while (current != NULL) {
        current = current->next; // go to the next node
        count++;
    }
    return count;
}

bool LinkedList::clearList(){
    bool success = false;
    if(head != NULL){
        Node *current = head;
        while(current != NULL){
            head = current->next;
            delete current;
            current = head;
        }
        head = NULL;
        success = true;
    }
    return success;
}

bool LinkedList::exists(int id) {
    bool flag = false;
    if (head != NULL) {
        Node *current = head; // NULL to current
        while (id != current->data.id && current->next != NULL) {
            current = current->next;
        }
        if (id == current->data.id) {
            flag = true;
        }
    }
    return flag;
}

// Private Methods
void LinkedList::addHead(int id, string* info, Node* current, Node* nodeHold) {
    nodeAllocate(id, info, &nodeHold);
    if(current == NULL){
        nodeHold->prev = NULL;
        nodeHold->next = NULL;
    }else
    {
        nodeHold->prev = NULL;
        nodeHold->next = current;
        current->prev = nodeHold;
    }
    head = nodeHold;
}

void LinkedList::addMiddle(int id, string *info, Node* current, Node* nodeHold){
    nodeAllocate(id, info, &nodeHold);
    nodeHold->next = current;
    nodeHold->prev = current->prev;
    current->prev->next = nodeHold;
    current->prev = nodeHold;
}

void LinkedList::addTail(int id, string *info, Node *current, Node* nodeHold){
    nodeAllocate(id, info, &nodeHold);
    nodeHold->next = NULL;
    nodeHold->prev = current;
    current->next = nodeHold;
}

void LinkedList::nodeAllocate(int id, string* info, Node** nodeHold){
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *info;
    *nodeHold = newNode;
}

