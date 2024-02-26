// Grace Lane
// 5 November 2022
// HW3.cpp
// Purpose: Given an array of n integers from user input, this program will
//  sort these integers using merge sort. Then it will print the sorted array.

#include <iostream>

using namespace std;

void merge(int A[], int start, int mid, int end) {           // for merging left and right sides all together
	int index, left, right, temp[end];
	index = start;
	left = start;
	right = mid + 1;
	while (left <= mid && right <= end) {       // while the left index is less than or equal to mid and right is less than or equal to the end
		if (A[left] < A[right]) {                 // if left is less than right then add left to temp array and increase index and left index by one
			temp[index] = A[left];
			index++;
			left++;
		}
		else  {                                   // else, add right to temp array and increase index and right by one
			temp[index] = A[right];
			index++;
			right++;
		}
	}
	while (left <= mid) {          // makes sure there is no more left in the array
		temp[index] = A[left];
		index++;
		left++;
	}
	while (right <= end) {         // makes sure there is no more left in the array
		temp[index] = A[right];
		index++;
		right++;
	}
	for (left = start; left < index; left++)  {              // puts everything back into A[] as sorted
		A[left] = temp[left];
	}
}

void mergeSort(int A[], int start, int end) {                
	if (start < end) {
		int mid = (start + end)/2;
		mergeSort(A, start, mid);
		mergeSort(A, mid + 1, end);
		merge(A, start, mid, end);
	}
}

int main () {
	int size;

	cout << endl;
	cout << "Welcome to HW3: Programming!" << endl;
	cout << "You will be asked to input integers for an array." << endl;
	cout << "This array will be sorted using merge sort and then " << endl;
	cout << "printed to the screen." << endl << endl;

	cout << "What size array would you like to input? ";
	cin >> size;
	cout << endl;

	int input;
	int arr[size];

	for (int i = 0; i < size; i++) {
		cout << "Please input an integer to be added to the array: ";
		cin >> input;
		arr[i] = input;
	}

	mergeSort(arr, 0, size-1);

	// print sorted array
	cout << endl;
	cout << "Sorted Array: ";
	for (int i = 0; i < size; i++) {              
		cout << arr[i] << " ";
	}
	cout << endl << endl;

	return 0;
}



