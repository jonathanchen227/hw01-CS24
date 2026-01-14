#include "intlist.h"
#include <iostream>
using std::cout;
// copy constructor
IntList::IntList(const IntList& source)
    :head(nullptr),tail(nullptr) {
        Node* curr = source.head;
        while ( curr ) {
            int a = curr->info;
            push_back(a);
            curr = curr -> next;
       }
}
// destructor deletes all nodes
IntList::~IntList() {
        Node* curr = this->head;
        while ( curr ) {
            Node* next = curr->next;
            delete curr;
            curr = next;
       }
}
void IntList::clear() {
    Node* curr = this->head;
        while ( curr ) {
            Node* next = curr->next;
            delete curr;
            curr = next;
       }
       this->head = this->tail = nullptr;
}
// return sum of values in list
int IntList::sum() const {
    int sum = 0 ;
    Node* curr = this->head;
    while ( curr ) {
        sum += curr -> info;
        curr = curr -> next;
   }
   return sum;
}
// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node* curr = this->head;
    while (curr) {
        if ( curr-> info  == value ) {
           return true;
        }
        curr = curr -> next;
   }
   return false;
}
// returns maximum value in list, or 0 if empty list
int IntList::max() const {
if ( this->head == nullptr) {
       return 0;
    }
    int max = 0 ;
    Node* curr = this->head;
    while ( curr ) {
        if ( curr -> info  > max ) {
             max = curr ->  info ;
        }
        curr = curr -> next;
   }
   return max;
}
// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    int count = 0;
    Node* curr = this->head;
    while ( curr ) {
       count++;
       curr = curr -> next;
   }
   if ( count == 0 ) {
       return 0;
   }
   return sum()/count; // REPLACE THIS NON-SOLUTION
}
// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node* newNode = new Node();
    newNode->info = value;
    newNode->next = head;
    head = newNode;
    if ( !this->tail) {
       this->tail = newNode;
    }
}
// append value at end of list
void IntList::push_back(int value) {
    Node* newNode = new Node();
    newNode->info = value;
    newNode->next = nullptr;
    if(!this->head) {
       this->head = this->tail = newNode;
    }
    else {
    this->tail->next = newNode;
    this->tail = newNode;
    }
}

// return count of values
int IntList::count() const {
  int count = 0;
  Node* curr = this->head;
  while(curr){
     count++;
     curr = curr->next;
  }
  return count;
}
//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if ( this == &source )
        return *this;
    this->clear();
    Node* curr = source.head;
    while ( curr ) {

push_back(curr->info);
       curr = curr -> next;
   }
   return *this;
}
// constructor sets up empty list
IntList::IntList():
    head(nullptr),tail(nullptr)
{}
// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)
// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = this->head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}



