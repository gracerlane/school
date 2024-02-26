// Grace Lane
// Stack.cpp
// Purpose: For defining the Stack's class fuctions
//  - Constructor- create empty stack
//  - Destructor- deallocate stack
//  - push()- add value to top of stack
//  - pop()- return value of top of stack and decrease top by 1
//  - isFull()- returns true if stack is full
//  - isEmpty()- returns true if stack is empty

#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

Stack::Stack()
{
	top = nullptr;
}

Stack::~Stack()
{
	StackNode *curr = top;
	StackNode *next = nullptr;

	while (curr != nullptr) {
		next = curr->next;
		delete curr;
		curr = next;
	}

	top = nullptr;
}

void Stack::push(int input)
{
	StackNode *newNode = new StackNode;
	newNode->num = input;

	if (isEmpty()) {
		top = newNode;
		newNode->next = nullptr;
	} else {
		newNode->next = top;
		top = newNode;
	}
}

int Stack::pop() {
	StackNode *temp = nullptr;

	if (isEmpty()) {
		cout << "The stack is empty." << endl;
		return -1;
	} else {
		int returnInt = top->num;
		temp = top->next;
		delete top;
		top = temp;
		return returnInt;
	}
}

bool Stack::isEmpty() const
{
	return top == nullptr;
}