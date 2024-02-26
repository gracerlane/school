// Grace Lane
// FancyList.cpp
// Purpose: For defining the FancyList class fuctions
//  -constructor
//  -destructor
//  -append
//  -print
//  -reverse
//  -deleteNode
//  Added to delete function to prevent numbers out of the range of the list size

#include <iostream>
#include <string>
#include "FancyList.h"

using namespace std;

// constructor
FancyList::FancyList()
{
	head = nullptr;                       
}

FancyList::~FancyList()
{
	cout << "Deallocating..." << endl;
	Node *current;                        // for transversing
	Node *next;                           // to point to next node after current
	current = head;                       // start at beginning
	while (current != nullptr) {
		next = current->next;               // next moves to node after current
		cout << "Deleting " << current->value << endl;
		delete current;                     // delete current node
		current = next;                     // current moves to next node
	}
	head = nullptr;                       // head becomes nullptr(empty list)
}

void FancyList::append(int num)
{
	Node *newNode;        // to point to a new node(what we want to append to the list)
	Node *current;        // to point to current node(as we transverse the list)

  newNode = new Node;                // allocate a new node and store num there
	newNode->value = num;
	newNode->next = nullptr;

	if (!head) {                       // if head is nullptr(no nodes in list)
		head = newNode;                  // head points to newNode
	} else {                       
		current = head;                  // current points to head(to start at the beginning)
		while (current->next) {          
			current = current->next;       // current moves to next node until it reaches the end of the list
		}
		current->next = newNode;         // current node points to new node(put as last node)
	}
}

void FancyList::printList()
{
  Node *current;        // for traversing
	current = head;       // start at beginning of list
  
	while (current != nullptr) {            // while there is a node
		cout << current->value << "  ";       // print value
		current = current->next;              // move to next node
	}
	cout << endl << endl;
}

void FancyList::reverse() 
{
	Node *prev = nullptr;                      // to point to previous node
	Node *current = head;                      // for transversing
	Node *next = nullptr;                      // to point to next node
	while (current != nullptr) {               // while there is a node
		next = current->next;                    // next moves to node after current
		current->next = prev;                    // node pointer moves to previous(becomes nullptr on first iteration)
		prev = current;                          // previous moves to current
		current = next;                          // current moves to next node
	}
	head = prev;
}

int FancyList::deleteNode(int nthNode)
{
	Node *previous = nullptr;       // to point to previous node(as we transverse the list)
	Node *current = nullptr;        // to point to current node(as we transverse the list)

	int count = 0;        // for counting number of nodes in list

	if (!head) {          // if head is nullptr(no nodes in list)
		return 0;    
	} else {
		current = head;
		while (current != nullptr) {          // counts the total nodes in the list
			count++;
			current = current->next;       
		}

		if (nthNode > count || nthNode < 1) {        // if the user inputed num is too small or too big
			return -1;
		}

		current = head;
		if (count == nthNode) {        // if deleting first node
			current = head->next;          // current moves to second node
			delete head;                   // deletes first node
			head = current;                // head points to second node
			count--;                   
		} else {
			while (count > nthNode) {    // until n away from end
				previous = current;          // previous moves to current
				current = current->next;     // current moves to next node
				count--;                   // count backwards from the end of the list
			}
			if (current) {                       // if current is not at the end
				previous->next = current->next;    // previous node points to node after current node(skip over current node)
				delete current;
			}
		}
	}
	return 1;
}