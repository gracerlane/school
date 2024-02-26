// Grace Lane
// Queue.h
// Purpose: For declaring the Queue class

#ifndef QUEUE_H
#define QUEUE_H

class Queue 
{
	private:
		int *queueArrPtr;   // points to the queue array
		int queueSize;      // size of the queue
		int front;          // front of the queue
		int rear;           // rear of the queue
		int numItems;       // number of items in the queue

	public:
		Queue(int);
		~Queue();
		void enqueue(int);
		int dequeue();
		bool isEmpty() const;
		bool isFull() const;
};


#endif