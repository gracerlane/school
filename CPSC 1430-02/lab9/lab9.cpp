// Grace Lane
// lab9.cpp
// Purpose: This program uses the Queue and Stack classes, which are defined 
//  in the Queue.h and Stack.h files. The Queue class's member and constructor
//  functions are defiend in the Queue.cpp file. The Stack class's member and 
//  constructor functions are defined in the Stack.cpp file. This program should
//  be compiled with those files.
//  In this lab, you will implement your own stack and queue to solve a problem: 
//  given an integer k and a queue of integers, you need to reverse the order of 
//  the first k integers, leaving the other integers in the same relative order.  
//  For example, given an integer k = 5 and a queue of integers: 1, 2, 3, 4, 5, 
//  6, 7, 8, 9, 10, the output should be 5, 4, 3, 2, 1, 6, 7, 8, 9, 10. 

#include <iostream>
#include <string>
#include "Stack.h"
#include "Queue.h"

using namespace std;

const int ARR_SIZE = 10;
const int ARRAY[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


int main(int argc, char * argv[])
{
	int target = stoi(argv[1]);                // target value to read backwards from

	Queue intQueue(ARR_SIZE);                  // creating the queue with the size of the array declared previously
	cout << "Original   array: ";
	intQueue.enqueue(ARRAY[0]);                // enqueue the first value of the array into the queue
	cout << "[" << ARRAY[0];
	for (int i = 1; i < ARR_SIZE; i++) {       // print and enqueue the following values of the array into the queue
		cout << ", " << ARRAY[i];
		intQueue.enqueue(ARRAY[i]);
	}
	cout << "]" << endl;

	Stack intStack(target);                           // creating the stack to help reverse the ints
	cout << "Reversed first " << target << ": ";
	for (int i = 0; i < target; i++) {                // pushing values by dequeue-ing them from the queue
		intStack.push(intQueue.dequeue());
	}

	cout << "[" << intStack.pop();                    // print the values in stack by poppping them out
	for (int i = 1; i < target; i++) {                // loop until the target value is reached
		cout << ", " << intStack.pop(); 
	}

	for (int i = target; i < ARR_SIZE; i++) {         // print out the rest of the values by dequeue-ing them from the queue
		cout << ", " << intQueue.dequeue();
	}
	cout << "]" << endl << endl;

	return 0;
}