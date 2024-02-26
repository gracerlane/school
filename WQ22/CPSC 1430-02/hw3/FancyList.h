// Grace Lane
// FancyList.h
// Purpose: For declaring the FancyList class

#include <iostream>

using namespace std;

#ifndef FANCYLIST_H       
#define FANCYLIST_H
class FancyList {
   private:
    struct Node{        // node for linked list to hold value and pointer
      int value;
      Node *next;
    };
    Node* head;         // head pointer
  public:
    FancyList();                   // constructor
    ~FancyList();                  // destructor
    void append(int num);          // appends node on linked list
    void printList();              // prints linked list
		void reverse();                // reverses linked list(1>2>3>4 becomes 4>3>2>1)
		int deleteNode(int nthNode);   // deletes node n away from end
};
#endif