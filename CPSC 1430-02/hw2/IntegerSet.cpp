// Grace Lane
// IntegerSet.cpp
// Purpose: For defining the IntegerSet class's functions
//  Constructors:
//	-One constructor does not have any parameters. This constructor initializes a 
//   set to the so-called “empty-set”, i.e., a set whose array representation 
//   contains all zeros. 
//  -An additional constructor that receives an array of integers and the size of 
//   that array and uses the array to initialize a set object.
//  Member Fuctions:
//  -A unionOfsets member function creates a third set that is the set-theoretic 
//   union of two existing sets (i.e., an element of the third array’s is set to 
//   1 if that element is 1 in either or both of the existing sets, and an element 
//   of the third set’s array is set to 0 if that element is 0 in each of the 
//   existing sets).
//  -An intersectionOfSets member function which creates a third set which is the 
//   set-theoretic intersection of two existing sets (i.e., an element of the third 
//   set’s array is set to 0 if that element is 0 in either or both of the existing
//   sets, and an element of the third set’s array is set to 1 in each of the 
//   existing sets).
//  -An insertElement member function inserts a new integer k into a set (be setting 
//   a[k] to 1).
//  -A deleteElement member function that deletes integer m (by setting a[m] to 0).
//  -A printSet member function prints a set as a list of numbers separated by spaces. 
//   Print only those elements that are present in the set (i.e., their position in 
//   the array has a value of 1).  Print – for an empty set. 
//  -An isEqualTo member function that determines whether two sets are equal.
//  -An emptySet member function that sets all elements of set to 0.
//  -An inputSet member function that reads value from user into the set.
//  -A validEntry member function that determines a valid entry to the set (i.e., 
//   in the range 0 through 100).

#include <iostream>
#include <string>
#include "IntegerSet.h"

using namespace std;


IntegerSet::IntegerSet()    // creates an array with all zeros
{
	nums[MAX] = {0};
}

IntegerSet::IntegerSet(int arrayOfInts[], int size)    // assigns the values of the user inputed array into the object array
{
	IntegerSet();
	for (int i = 0; i < size; i++) {
		nums[arrayOfInts[i]] = 1;
	}
}

void IntegerSet::printSet()
{
	cout << "{ ";
	for (int i = 0; i < MAX; i++) {
		if (nums[i] == 1) {	
			cout << i << " ";
		}
	}
	cout << "}" << endl;
}

IntegerSet IntegerSet::unionOfsets(IntegerSet arr2)
{
	IntegerSet unionSet;
	for (int i = 0; i < MAX; i++) {
		if (nums[i] || arr2.nums[i]){
			unionSet.nums[i] = 1;
		}
	}

	return unionSet;
}

IntegerSet IntegerSet::intersectionOfSets(IntegerSet arr2)
{
	IntegerSet interSet;
	for (int i = 0; i < MAX; i++) {
		if (nums[i] && arr2.nums[i]) {
			interSet.nums[i] = 1;
		}
	}
	return interSet;
}

bool IntegerSet::isEqualTo(IntegerSet arr2)
{
	for (int i = 0; i < MAX; i++) {
		if (nums[i] != arr2.nums[i]) {
			return false;
		}
	}
	return true;
}

void IntegerSet::insertElement(int element)
{
	nums[element] = 1;
}

void IntegerSet::deleteElement(int element)
{
	nums[element] = 0;
}

void IntegerSet::emptySet()
{
	for (int i = 0; i < MAX; i++) {
		nums[i] = 0;
	}
}

void IntegerSet::inputSet(int element)
{
		nums[element] = 1;
}

bool IntegerSet::validEntry(int element)
{
	if (element > MAX || element < MIN) {
		return false;
	}
	return true;
}

