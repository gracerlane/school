// Grace Lane
// 3 June 2022
// lab5.cpp
// Purpose: Heap Sort, Merge Sort, and Quick Sort implentation 
//  and their respective execution times.

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void heapify(int A[], int c, int p) {                 // heapify the child and parent until they are in the correct spots
	if (A[c] > A[p]) {
		int t = A[c];
		A[c] = A[p];
		A[p] = t;
		c = p;
		p = (c-1)/2;
		heapify(A, c, p);
	}
}

void heapSort(int A[], int n) {                       // Heap sort
	cout << "Heap Sort" << endl;
	int index = -1;
	int heapArr[n];                                     // initializes the temp array used for this sort

	for (int i = 0; i < n; i++) {
		// int element = A[i];                               // element is the current element in A[]
		// index++;
		heapArr[i] = A[i];                         // add element to the heap array at index
		int child = i;
		int parent = (i-1)/2;
		heapify(heapArr, child, parent);
	}
for (int i = 0; i < n; i++) {                       // prints sorted array (used to verify sorting algorithm is correct)
		cout << heapArr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		int element = A[i];                               // element is the current element in A[]
		index++;
		heapArr[index] = element;                         // add element to the heap array at index
		int child = index;
		int parent = (index-1)/2;
		heapify(heapArr, child, parent);
	}
	for (int i = 0; i < n; i++) {                       // assigns the appropriate values from heapArr[] to A[]
		A[i] = heapArr[i];
	}
	
	for (int i = 0; i < n; i++) {                       // prints sorted array (used to verify sorting algorithm is correct)
		cout << A[i] << " ";
	}
	cout << endl;
}

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

void mergeS(int A[], int start, int end) {      // recursively calls itself until it reaches the end and then merges the left and right
	if (start < end) {
		int mid = (start + end)/2;
		mergeS(A, start, mid);
		mergeS(A, mid + 1, end);
		merge(A, start, mid, end);
	}
}

void mergeSort(int A[], int n) {                // Merge sort
	cout << "Merge Sort" << endl;
	int start = 0;
	int end = n - 1;
	mergeS(A, start, end);                        // calls mergeS with the array and start and ending indexes
	
	// for (int k = 0; k < n; k++) {                 // prints sorted array (used to verify sorting algorithm is correct)
	// 	cout << A[k] << " ";
	// }
	// cout << endl << endl;
}

void swap(int *x, int *y) {        // swaps x and y
	int t = *x;
	*x = *y;
	*y = t;
}

int partition(int A[], int start, int end) {       // divides left and right sides and swaps accordingly and returns pivot index
	int pivot = A[start];
	int num = (start + 1);

	for(int i = (start + 1); i <= end; i++) {
		if(A[i] < pivot) {
			if(i != num) {
				swap(&A[num], &A[i]);
			}
			num++;
		}
	}

	A[start]=A[num - 1];
	A[num - 1]=pivot;
	return (num - 1);
}

void quickS(int A[], int start, int end) {          // calls partition to find index of pivot, then recursively calls until start = end
	if (start < end) { 
		int pivot = partition(A, start, end);
		quickS(A, start, pivot - 1);
		quickS(A, pivot + 1, end);
	}
}

void quickSort(int A[], int n) {                   // Quick sort
	cout << "Quick Sort" << endl;
	int start = 0;
	int end = (n - 1);
	quickS(A, start, end);
	// for (int i = start; i <= end; i++) {                    // prints sorted array (used to verify sorting algorithm worked)
	// 	cout << A[i] << " ";
	// }
	// cout << endl;
}

int main()
{
	// uncommented each sorting algoithm one at a time to test time

	srand(time(NULL));


	int size[] = {10, 100, 1000, 10000};
	for(int i = 0; i < 4; i ++){
		int unsortedArray[size[i]]; 
		cout << "The current array size is: " << size[i] << endl;
		for(int j = 0; j < size[i]; j++){
			unsortedArray[j] = (rand() % 1000000);
		}
		
		// for(int j = 0; j < size[i]; j++){                          // prints out unsorted array (commented out during testing so I could see all the times at the same time)
		// 	cout << unsortedArray[j] << endl;
		// }

		// HEAP SORT
		auto start = high_resolution_clock::now();	  	              // set a clock before the program executes
		heapSort(unsortedArray, size[i]);
		auto stop = high_resolution_clock::now(); 	                 	// set a clock after the program executes
		auto duration = duration_cast<nanoseconds>(stop - start); 		// get the execution time by calculating the difference between two clocks
		cout << "TIME: " << duration.count() << endl << endl;        // output the duration

		// MERGE SORT
		// auto start = high_resolution_clock::now();
		// mergeSort(unsortedArray, size[i]);
		// auto stop = high_resolution_clock::now();
		// auto duration = duration_cast<nanoseconds>(stop - start);
		// cout << "TIME: " << duration.count() << endl << endl;

		// QUICK SORT
		// auto start = high_resolution_clock::now();
		// quickSort(unsortedArray, size[i]);
		// auto stop = high_resolution_clock::now();
		// auto duration = duration_cast<nanoseconds>(stop - start);
		// cout << "TIME: " << duration.count() << endl << endl;
			
	}

	return 0;

} 