// Grace Lane
// Queue.cpp
// Purpose: For defining the Queue's class fuctions
//  - Constructor- create empty stack
//  - Destructor- deallocate stack
//  - enqueue()- add value to end of queue
//  - dequeue()- return value of first and decrease by one
//  - isEmpty()- returns true if stack is empty

#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

Queue::Queue() 
{
	front = nullptr;
	rear = nullptr;
	numItems = 0;
}


void Queue::enqueue(int num)
{
	QueueNode *newNode = new QueueNode;
	newNode->val = num;
	newNode->next = nullptr;

	if (isEmpty()) {
		front = newNode;
		rear = newNode;
	} else {
		rear->next = newNode;
		rear = newNode;
	}

	numItems++;
}

int Queue::dequeue()
{
	if (isEmpty()) {
		cout << "The queue is empty." << endl;
		return -1;
	} else {
		int returnVal = front->val;
		QueueNode *temp = front;
		front = front->next;

		delete temp;
		numItems++;
		return returnVal;
	}
}

bool Queue::isEmpty() const
{
	return numItems == 0;
}