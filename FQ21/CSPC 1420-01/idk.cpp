// Grace Lane
// Stack.h
// Purpose: For declaring the Stack class

#ifndef STACK_H
#define STACK_H

class Stack 
{
	private:
	  struct StackCharNode {
			char charVal;
			StackCharNode *charNext;
		};
		StackCharNode *charTop;

		struct StackIntNode {
			int intVal;
			StackIntNode *intNext;
		};
		StackIntNode *intTop;
	
	public:
		IntStack();
		CharStack();
		~Stack();
		void pushChar(char);
		void pushInt(int);
		char popChar();
		int popInt();
		bool charIsEmpty() const;
		bool intIsEmpty() const;
};
#endif


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
	intTop = nullptr;
}

// Stack::~Stack()
// {
// 	StackNode *curr = top;
// 	StackNode *next = nullptr;

// 	while (curr != nullptr) {
// 		next = curr->next;
// 		delete curr;
// 		curr = next;
// 	}

// 	top = nullptr;
// }

void Stack::pushChar(char input)
{
	StackCharNode *newNode = new StackCharNode;
	newNode->charVal = input;

	if (charIsEmpty()) {
		charTop = newNode;
		newNode->charNext = nullptr;
	} else {
		newNode->charNext = charTop;
		charTop = newNode;
	}
}

void Stack::pushInt(int num)
{
	StackIntNode *newNode = new StackIntNode;
	newNode->intVal = num;

	if (intIsEmpty()) {
		intTop = newNode;
		newNode->intNext = nullptr;
	} else {
		newNode->intNext = intTop;
		intTop = newNode;
	}
}

char Stack::popChar() 
{
	StackCharNode *temp = nullptr;

	if (charIsEmpty()) {
		cout << "The stack is empty." << endl;
		return -1;
	} else {
		char returnChar = charTop->charVal;
		temp = charTop->charNext;
		delete charTop;
		charTop = temp;
		return returnChar;
	}
}

int Stack::popInt() 
{
	StackIntNode *temp = nullptr;

	if (intIsEmpty()) {
		cout << "The stack is empty." << endl;
		return -1;
	} else {
		int returnInt = intTop->intVal;
		temp = intTop->intNext;
		delete intTop;
		intTop = temp;
		return returnInt;
	}
}

bool Stack::charIsEmpty() const
{
	return charTop == nullptr;
}

bool Stack::intIsEmpty() const
{
	return intTop == nullptr;
}



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


// Grace Lane
// hw4_5.cpp
// Purpose: This program uses the Queue and Stack classes, which are defined 
//  in the Queue.h and Stack.h files. The Queue class's member and constructor
//  functions are defiend in the Queue.cpp file. The Stack class's member and 
//  constructor functions are defined in the Stack.cpp file. This program 
//  should be compiled with those files.
//  This programming assignment is divided into two tasks to practice stack 
//  and queue:
//   For the first task,  you will write a code to evaluate a string and 
//   output its mathematical value. Yes, a very very simple calculator! 
//   Specifically, you will implement linked list-based stack(s). Note that 
//   depending on your algorithm implementation, you can have one or multiple 
//   stacks of different data types. With the help of your stack(s), you will 
//   design your algorithm that can process a given string that represents a math 
//   expression, and output its value. For example, for a given string "2+3-4", 
//   your program should output 1; for a given string "10+2+3-5-2", your program 
//   should output 8. Note that you can assume:
//    - the string expression will be always valid 
//    - the string only contains digits and +, -
//   For the second task, you will work on solving the following question: given 
//   a window size (passed in when running) and an integer array (saved in an 
//   input file where each line contains one element), your algorithm should 
//   calculate the average of the numbers in a sliding window which slides from 
//   the beginning to the end of the array. Note that integer division will 
//   truncate toward zero. For example, assuming the array is [1, 2, 3, 4, 5, 6, 
//   7, 8, 9, 10] and the window size is 3, your program should output the
//   following: 2, 3, 4, 5, 6, 7, 8, 9, where:
//    - 2 is the average of numbers in the first window [1, 2, 3]
//    - 3 is the average of numbers in the second window [2, 3, 4]
//    - 4 is the average of numbers in the third window [3, 4, 5]

#include <iostream>
#include <string>
#include <fstream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

const string STOP = "#";

int main(int argc, char * argv[])
{
	string expression;
	char charInput;

	Stack stackChar;
	Stack stackInt;
	

	cout << "****Showcasing the first task****" << endl;
	while (true) {
		cout << "    Type the expression (type " << STOP << " to quit):";
		cin >> expression;
		if (expression == STOP) {
			break;
		}
		else {
			for (int i = 0; i < expression.size(); i++){
    		charInput = expression[i];
				if (charInput == '+' || charInput == '-') {
					cout << charInput << endl;
					stackChar.pushChar(charInput);
				} else {
					int num = (int)charInput;
					num = (num-48);
					cout << num << endl;
					stackInt.pushInt(num);
				}
			}
		}
	}

	cout << endl << endl;


	ifstream input;                            // for file input
	string inputFile;                          // for file input
	Queue fileQueue;                           // new queue
	int window = stoi(argv[2]);                // window size (string to int)
	int num;                                   // to help find average

	input.open(inputFile);

	cout << "****Showcasing the second task****" << endl;
	cout << "    The averages in each window of size " << window << " are [";
	
	while (num) {
		fileQueue.enqueue(num);
	}

	while (num) {
		cout << fileQueue.dequeue() << endl;
	}



  cout << endl;
	
  
  
	
	return 0;

}