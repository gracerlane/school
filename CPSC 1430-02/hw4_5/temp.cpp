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

bool isOperator(const string &expression);

int calculate();

int main(int argc, char * argv[])
{
	string expression;
	char input;
	int num = 0;

	Stack intStack;

	int size;
	int result = 0;
	int term1 = 0;
	int term2 = 0;
	char operate;
	

	int index = 0;

	cout << "****Showcasing the first task****" << endl;
	while (true) {
		cout << "    Type the expression (type " << STOP << " to quit):";
		cin >> expression;
		size = expression.size();
		if (expression == STOP) {
			break;
		}
		else {
			while (index < size) {
				cout << "num starting: " << num << endl;
				cout << "char: " << expression[index] << endl;

				while (isdigit(expression[index])){
					num = num * 10 + (expression[index] - '0');
					cout << "num: " << num << endl;
					index++;
					if (!isdigit(expression[index])) {
						cout << "     pushing num before op: " << num << endl;
						intStack.pushInt(num);
						num = 0;
					}
				}

				if (expression[index] == '-') {
					index++;
					num = num * 10 + (expression[index] - '0');
					cout << "num with - before it: " << num << endl;
					index++;
					while (isdigit(expression[index])){
						num = num * 10 + (expression[index] - '0');
						cout << "num: " << num << endl;
						index++;
					} 
					num = (num * -1);
					cout << "     pushing - num before op: " << num << endl;
					intStack.pushInt(num);
					num = 0;
				} else if (expression[index] == '+'){
					index++;
					num = num * 10 + (expression[index] - '0');
					cout << "num with + before it: " << num << endl;
					index++;
					while (isdigit(expression[index])){
						num = num * 10 + (expression[index] - '0');
						cout << "num: " << num << endl;
						index++;
					}
					cout << "     pushing num before op: " << num << endl;
					intStack.pushInt(num);
					num = 0;
				}
		
			}

			cout << index << endl;
			num = 0;
			index = 0;
		}
	
	
  while (!intStack.isEmptyInt()) {
		term2 = intStack.popInt();
		cout << "calculating: " << term1 << " + " << term2 << endl;

		term1 = term1 + term2;

		cout << "result/term1: " << term1 << endl;
	}

	cout << "    The value of this expression is t1: " << term1 << endl;
	term1 = 0;
	}
	
	return 0;
}