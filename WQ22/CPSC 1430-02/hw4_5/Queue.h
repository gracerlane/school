// Grace Lane
// Queue.h
// Purpose: For declaring the Queue class

#ifndef QUEUE_H
#define QUEUE_H

class Queue {
	private:
		struct QueueNode {
			int val;                 // value in node
			QueueNode *next;         // pointer to the next node
		};

		QueueNode *front;
		QueueNode *rear;
		int numItems;

	public:
		Queue();

		void enqueue(int);
		int dequeue();
		bool isEmpty() const;
};
#endif