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

Stack::Stack(int size)
{
	stackArrPtr = new int[size];
	stackSize = size;
	top = -1;                     // empty stack
}

Stack::~Stack()
{
	delete [] stackArrPtr;
}

void Stack::push(int input)
{
	if (isFull()) {
		cout << "The stack is full." << endl;
	} else {
		top++;
		stackArrPtr[top] = input;
	}
}

int Stack::pop() {
	if (isEmpty()) {
		cout << "The stack is empty." << endl;
		return -1;
	} else {
		int value = stackArrPtr[top];
		top--;
		return value;
	}
}

bool Stack::isFull() const
{
	return top == stackSize - 1;
}

bool Stack::isEmpty() const
{
	return top == -1;
}