// Grace Lane
// Queue.cpp
// Purpose: For defining the Queue's class fuctions
//  - Constructor- create empty stack
//  - Destructor- deallocate stack
//  - enqueue()- add value to end of queue
//  - dequeue()- return value of first and decrease by one
//  - isFull()- returns true if stack is full
//  - isEmpty()- returns true if stack is empty

#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

Queue::Queue(int size) 
{
	queueArrPtr = new int[size];
	queueSize = size;
	front = -1;
	rear = -1;
	numItems = 0;
}

Queue::~Queue()
{
	delete [] queueArrPtr;
}

void Queue::enqueue(int input)
{
	if (isFull()) {
		cout << "The queue is full." << endl;
	} else {
		rear =  (rear + 1) % queueSize;
		queueArrPtr[rear] = input;
		numItems++;
	}
}

int Queue::dequeue()
{
	if (isEmpty()) {
		cout << "The queue is empty." << endl;
		return -1;
	} else {
		front = (front + 1) % queueSize;
		numItems--;
		return queueArrPtr[front];
	}
}

bool Queue::isEmpty() const
{
	return numItems == 0;
}

bool Queue::isFull() const
{
	return numItems == queueSize;
}