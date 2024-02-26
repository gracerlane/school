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

const string STOP = "#";        // for exiting the first task

int main(int argc, char * argv[])
{
	string expression;   // for user input
	int num = 0;

	Stack intStack;

	int size = 0;
	int term = 0;
	int result = 0;

	int index = 0;

	cout << "****Showcasing the first task****" << endl;
	while (true) {
		cout << "    Type the expression (type " << STOP << " to quit):";
		cin >> expression;
		cin.ignore();
		if (expression == STOP) {
			break;
		}
		else {
			size = expression.size();
			while (index < size) {
				while (isdigit(expression[index])){
					num = num * 10 + (expression[index] - '0');
					index++;
					if (!isdigit(expression[index])) {
						intStack.push(num);
						num = 0;
					}
				}

				if (expression[index] == '-') {
					index++;
					num = num * 10 + (expression[index] - '0');
					index++;
					while (isdigit(expression[index])){
						num = num * 10 + (expression[index] - '0');
						index++;
					} 
					num = (num * -1);
					intStack.push(num);
					num = 0;
				} else if (expression[index] == '+'){
					index++;
					num = num * 10 + (expression[index] - '0');
					index++;
					while (isdigit(expression[index])){
						num = num * 10 + (expression[index] - '0');
						index++;
					}
					intStack.push(num);
					num = 0;
				}
			}
			num = 0;
			index = 0;
		}
		while (!intStack.isEmpty()) {
			term = intStack.pop();
			result = result + term;
		}

		cout << "    The value of this expression is " << result << endl << endl;
		result = 0;
	}


	ifstream input;                            // for file input
	string inputFile;                          // for file input
	Queue fileQueue;                           // new queue
	Queue averages;                            // queue for averages
	int window = stoi(argv[2]);                // window size (string to int)
	int avg = 0;                               // to help find average
	int count = 0;                             // count number of ints
	int lines = 0;                             // to count lines in file
	int temp = 0;
	int fileInt;
	int first = 0;

	inputFile = argv[1];
	input.open(inputFile);

	if (input.fail()) {
		cout << endl;
		cout << "file error... exiting program... press enter...";
		cin.get();
		cout << endl;
		return 0;
  }

	if (input.is_open()) {                 // checks the file is open and counts the number of lines
		while (input >> fileInt) {
			lines++;
		}
	}
	input.close();

	input.open(inputFile);

	int total = (lines - window) + 1;


	if (input.is_open()) {                 // checks the file is open and counts the number of lines
		while (count < total) {
			avg = 0;
			input >> fileInt;
			fileQueue.enqueue(fileInt);
			if (count == 0) {                         // only runs at beginning of file
				for (int i = 1; i < window; i++) {
					input >> fileInt;

					fileQueue.enqueue(fileInt);
				}
			}

			first = fileQueue.dequeue();
			avg += first;
			for (int i = 1; i < window; i++) {
				temp = fileQueue.dequeue();
				avg += temp;
				fileQueue.enqueue(temp);
			}
			avg = avg/window;
			averages.enqueue(avg);
			count++;
		}
	}
	input.close();

	cout << endl << endl;
	cout << "****Showcasing the second task****" << endl;
	cout << "    The averages in each window of size " << window << " are [";

	for (int i = 1; i < count; i++) {
		cout << " " << averages.dequeue();
	}
	cout << " ]" << endl;	
  
	
	return 0;

}