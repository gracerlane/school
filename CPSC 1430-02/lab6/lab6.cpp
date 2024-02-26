// Grace Lane
// lab6.cpp
// Purpose: This program uses the IntegerSet class, which is defined 
//  in the IntegerSet.h fild. The IntegerSet class's member and constructor
//  functions are defiend in the IntegerSet.cpp file. This program should
//  be compiled with those files.
//  -A user can insert any typed integer number into the list 
//   of an OrderedList instance.
//  -The list order of any OrderedList instance is always 
//   non-descending. That is, whenever printList() is called, 
//   all the elements will be printed out in a non-descending way.
//  -class OrderedList should have a proper destructor to 
//   deallocate nodes from memory.
//  -class OrderedList should have a proper copy constructor to 
//   deep copy all the nodes in the input list.

#include <iostream>
#include <string>
#include "OrderedList.h"

using namespace std;

const string STOP = "x"; 

int main()
{
	OrderedList listA;
	string inputA;
	string inputB;
	int numA;
	int numB;

	cout << "Asking user to type and create listA..." << endl;
	while (true) {
		cout << endl;
		cout << "Type a number for insertion (type " << STOP << " to stop): ";
		cin >> inputA;
		if (inputA == STOP) {
			break;
		}
		else {
			numA = atoi(inputA.c_str());
			listA.insert(numA);
		}
	}
	cout << endl;

	cout << endl;
	cout << "listA is:                   ";
	listA.printList();
	cout << endl;

	cout << endl;
	cout << "listB is copied from listA: ";
	OrderedList listB = listA;
	listB.printList();
	cout << endl;
	
	cout << endl << endl;
	cout << "Asking user to type and add more to listB..." << endl;
	while (true) {
		cout << endl;
		cout << "Type a number for insertion (type " << STOP << " to stop): ";
		cin >> inputB;
		if (inputB == STOP) {
			break;
		}
		else {
			numB = atoi(inputB.c_str());
			listB.insert(numB);
		}
	}

	cout << endl << endl;
	cout << "listA now is: ";
	listA.printList();
	cout << endl;

	cout << endl;
	cout << "listB now is: ";
	listB.printList();
	cout << endl;

	return 0;
}