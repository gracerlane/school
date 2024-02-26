// Grace Lane
// 5 November 2022
// HW3.cpp
// Purpose: Given an array of n integers from user input, this program will
//  sort these integers using merge sort. Then it will print the sorted array.

#include <iostream>

using namespace std;

void merge(int A[], int start, int mid, int end) {           // for merging left and right sides all together
	int index, left, right;
	int *tempPtr =  new int (end);
	index = start;
	left = start;
	right = mid + 1;
	while (left <= mid && right <= end) {       // while left is less than or equal to mid and right is less than or equal to end
		if (A[left] < A[right]) {                 // if left is less than right then add left to temp array and increase index and left index by one
			tempPtr[index] = A[left];
			index++;
			left++;
		}
		else  {                                   // else, add right to temp array and increase index and right by one
			tempPtr[index] = A[right];
			index++;
			right++;
		}
	}
	while (left <= mid) {          // makes sure there is no more left in the array
		tempPtr[index] = A[left];
		index++;
		left++;
	}
	while (right <= end) {         // makes sure there is no more left in the array
		tempPtr[index] = A[right];
		index++;
		right++;
	}
	for (left = start; left < index; left++)  {              // puts everything back into A[] as sorted
		A[left] = tempPtr[left];
	}
}

void mergeSort(int A[], int start, int end) {               // recursively calls mergeSort for left then right then calls merge to merge them
	if (start < end) {
		int mid = (start + end)/2;
		mergeSort(A, start, mid);
		mergeSort(A, mid + 1, end);
		merge(A, start, mid, end);
	}
}

int main () {

	// Welcome message
	cout << endl;
	cout << "Welcome to HW3: Programming!" << endl;
	cout << "You will be asked to input integers for an array." << endl;
	cout << "This array will be sorted using merge sort and then " << endl;
	cout << "printed to the screen." << endl << endl;

	int size;       // used to determine the size of the array from user
	cout << "What size array would you like to input? ";
	cin >> size;
	cout << endl;

	// creates dynamic array
	int *arrPtr = new int (size);

	// asks for integer for array until the size of the array is met
	for (int i = 0; i < size; i++) {
		cout << "Please input an integer to be added to the array: ";
		cin >> arrPtr[i];
	}

	// calls mergeSort to start merging
	mergeSort(arrPtr, 0, size-1);

	// print sorted array
	cout << endl;
	cout << "Sorted Array: ";
	for (int i = 0; i < size; i++) {              
		cout << arrPtr[i] << " ";
	}
	cout << endl << endl;

	// deallocates array
	delete [] arrPtr;
	arrPtr = nullptr;

	return 0;
}



