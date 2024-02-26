// Grace Lane
// hw2.cpp
// Purpose: This program uses the IntegerSet class, which is defined 
//  in the IntegerSet.h fild. The IntegerSet class's member and constructor
//  functions are defiend in the IntegerSet.cpp file. This program should
//  be compiled with those files.
//  This program creates a class IntegerSet for which each object can hold 
//  integers in the range 0 through 100. A set is represented internally 
//  as an array of ones and zeros; array elements a[i] is 1 if integer i is 
//  in the set. The program asks the user to input values for two sets.
//  Then it calls the member functions according to sample Output from Canvas.
//  Set A
//  Set B
//  Union
//  Intersection
//  Equal to
//  Delete
//  New array hardcoded to test the bounds limit for Set C

#include <iostream>
#include <string>
#include "IntegerSet.h"

using namespace std;

const string STOP = "x";

int main(int argc, char *argv[])
{
	int validArray[10] = {25, 67, 2, 9, 99, 105, 45, -5, 100, 1};
	bool equalTo;
	bool valid;
	int input;
	string element1;
	string element2;
	IntegerSet setA;
	IntegerSet setB;
	IntegerSet setForUnion;
	IntegerSet setForInter;
	IntegerSet validSet;
	cout << "Enter set A:" << endl;
	while (true) {
		cout << "Enter an element (Type " << STOP << " to stop): ";
		cin >> element1;
		if (element1 == STOP) {
			break;
		}
		else {
			int input1 = atoi(element1.c_str());
			setA.inputSet(input1);
		}
	}
	cout << "Entry complete" << endl;
	cout << endl;


	cout << "Enter set B:" << endl;
	while (true) {
		cout << "Enter an element (Type " << STOP << " to stop): ";
		cin >> element2;
		if (element2 == STOP) {
			break;
		}
		else {
			int input2 = atoi(element2.c_str());
			setB.inputSet(input2);
		}
	}
	cout << "Entry complete" << endl;
	cout << endl;

	setForUnion = setA.unionOfsets(setB);
	cout << "Union of A and B is:" << endl;
	setForUnion.printSet();
	cout << endl;

	setForInter = setA.intersectionOfSets(setB);
	cout << "Intersection of A and B is:" << endl;
	setForInter.printSet();
	cout << endl;

	equalTo = setA.isEqualTo(setB);
	if (equalTo) {
		cout << "Set A is equal to Set B" << endl;
	} else {
		cout << "Set A is not equal to Set B" << endl;
	}

	cout << "What element would you like to insert into Set A?: ";
	cin >> input;
	setA.insertElement(input);
	cout << "Set A is now:" << endl;
	setA.printSet();
	cout << endl;

	cout << "Deleting " << input << " from Set A..." << endl;
	setA.deleteElement(input);
	cout << "Set A is now:" << endl;
	setA.printSet();
	cout << endl;

	cout << "Now creating a set of specific values and testing the bounds limits." << endl;
	cout << "Creating array of size 10: {";
	for (int i = 0; i < 9; i++) {
		cout << validArray[i] << ", ";
	}
	cout << validArray[9] << "}" << endl;
	for (int i = 0; i < 10; i++) {
		valid = validSet.validEntry(validArray[i]);
		if (!valid) {
			cout << "Invalid insert of " << validArray[i] << " attempted!" << endl;
		} else {
			validSet.inputSet(validArray[i]);
		}
	}
	cout << endl;
	cout << "Set C is:" << endl;
	validSet.printSet();
	cout << endl;

	return 0;
}