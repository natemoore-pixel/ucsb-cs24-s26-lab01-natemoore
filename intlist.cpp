// intlist.cpp
// Implements class IntList
// Nate Moore, 4/7/26

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    head = nullptr;
    tail = nullptr;

    Node* curr = source.head;
    while (curr != nullptr) {
        push_back(curr->info);
        curr = curr->next;
    }
}

// destructor deletes all nodes
IntList::~IntList() {
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    int total = 0;
    Node* curr = head;

    while (curr != nullptr) {
        total += curr->info;
        curr = curr->next;
    }

    return total;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = head;

    while (curr != nullptr) {
        if (curr->info == value) {
            return true;
        }
        curr = curr->next;
    }

    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    if (head == nullptr) {
        return 0;
    }

    int maximum = head->info;
    Node* curr = head->next;

    while (curr != nullptr) {
        if (curr->info > maximum) {
            maximum = curr->info;
        }
        curr = curr->next;
    }

    return maximum;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    if (head == nullptr) {
        return 0.0;
    }

    return static_cast<double>(sum()) / count();
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = head;

    head = newNode;

    if (tail == nullptr) {
        tail = newNode;
    }
}

// append value at end of list
void IntList::push_back(int value) {
    Node* newNode = new Node;
    newNode->info = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// return count of values
int IntList::count() const {
    int cnt = 0;
    Node* curr = head;

    while (curr != nullptr) {
        cnt++;
        curr = curr->next;
    }

    return cnt;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) {
        return *this;
    }

    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    head = nullptr;
    tail = nullptr;

    curr = source.head;
    while (curr != nullptr) {
        push_back(curr->info);
        curr = curr->next;
    }

    return *this;
}

// constructor sets up empty list
IntList::IntList(){
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}
