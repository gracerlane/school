// IntegerSet.h
// Purpose: For declaring IntegerSet class

#include <iostream>

using namespace std;

#ifndef INTEGERSET_H
#define INTEGERSET_H

const int MAX = 101;
const int MIN = 1;

class IntegerSet 
{
	private:
		int nums[MAX] = {0}; // creates array to hold 100 elements
	public:
		IntegerSet();
		IntegerSet(int arrayOfInts[], int size);
		void printSet();
		IntegerSet unionOfsets(IntegerSet arr2);
		IntegerSet intersectionOfSets(IntegerSet arr2);
		bool isEqualTo(IntegerSet arr2);
		void insertElement(int element);
		void deleteElement(int element);
		void emptySet();
		void inputSet(int element);
		bool validEntry(int element);

};



#endif