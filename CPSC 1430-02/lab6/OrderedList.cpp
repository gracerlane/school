// Grace Lane
// OrderedList.cpp
// Purpose: For defining the Player's class fuctions

#include <iostream>
#include <string>
#include "OrderedList.h"

using namespace std;

// constructor
OrderedList::OrderedList()
{
	head = nullptr;
}

// copy constructor
OrderedList::OrderedList(OrderedList &orig)
{
	if (orig.head == nullptr) {           // if the list is empty make other copied empty
		head = nullptr;
	} else {
		Node *currNode = orig.head;         // to move through list  
		head = new Node;                    // allocate new Node
		head->value = currNode->value;      // head value set equal to listA value
		head->next = nullptr;               // head pointer points to null
		Node *listBNode;                    // pointer for listB nodes
		listBNode = head;                   // first listB node assigned to head
		currNode = currNode->next;          // current becomes next pointer
		while (currNode != nullptr) {
			listBNode->next = new Node;               // allocate new Node for listB
			listBNode = listBNode->next;              // listBNode node becomes pointer to next node
			listBNode->value = currNode->value;       // values assigned
			listBNode->next = nullptr;                // node pointer
			currNode = currNode->next;                // current node becomes next pointer
		}
	}
}

// destructor
OrderedList::~OrderedList()
{
	cout << endl;
	cout << "Deallocating..." << endl;
	cout << endl;
	Node *currNode;            // for transversing;
	Node *next;                // to point to next node
	currNode = head;           // start at beginning
	while (currNode != nullptr) {
		next = currNode->next;          // next points to next node
		cout << "Deleting " << currNode->value << endl << endl;
		delete currNode;                // delete current node
		currNode = next;                // current become the next node
	}
	head = nullptr;
}

// function to insert node into linked list
void OrderedList::insert(int num)
{
	Node *previous;       // to point to previous node(as we transverse the list)
	Node *newNode;        // to point to a new node(what we want to insert in the list)
	Node *current;        // to point to current node(as we transverse the list)

  newNode = new Node;            // allocate a new node and store num there
	newNode->value = num;
	newNode->next = nullptr;

	if (!head) {                   // if head is nullptr(no nodes in list)
		head = newNode;              // head points to newNode
		newNode->next = nullptr;     // newNode points to nullptr
	} else {                       
		current = head;              // current node is the head to start at the beginning
		previous = nullptr;          // previous node is nullptr(nothing before head pointer)
		while (current != nullptr && current->value < num) {     // skips first node and nodes with values less than num(to sort the nodes)
			previous = current;        // previous points to current node
			current = current->next;   // current points to next node
		}
		if (previous == nullptr) {         // if first node
			head = newNode;                  // head points to newNode
			newNode->next = current;         // newNode points to current
		} else {                           // else, insert after previous
			previous->next = newNode;        // previous points to newNode
			newNode->next = current;         // newNode points to current
		}
	}
}

void OrderedList::printList()
{
  Node *curr;        // to read through the list
	curr = head;       // start at beginning of list
  
	while (curr != nullptr) {            // while there is a node
		cout << curr->value << " ";        // print value
		curr = curr->next;                 // move to next node
	}
}