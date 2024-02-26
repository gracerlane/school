// Grace Lane
// OrderedList.h
// Purpose: For declaring the OrderedList class

#include <iostream>

using namespace std;

#ifndef ORDEREDLIST_H       
#define ORDEREDLIST_H
class OrderedList {
   private:
    struct Node{        // node for linked list to hold value and pointer
      int value;
      Node *next;
    };
    Node* head;         // head pointer
  public:
    OrderedList();                  // constructor
    OrderedList(OrderedList &);     // copy constructor
    ~OrderedList();                 // destructor
    void insert(int);               // inserts node into linked list
    void printList();               // prints linked list
};
#endif