// Grace Lane
// 5 May 2022
// lab4.cpp
// Revised code given by professor

/* 
** Min-Heap construction and basic operations 
** Lab 4, CPSC 2430, Xin Zhao
*/

#include <iostream>
using namespace std;

// define the max size for the heap array 
const int HEAP_MAX_SIZE = 1000;

class MinHeap {
	private:
    int heapArr[HEAP_MAX_SIZE];
    int size;

    void swap(int x, int y) {
    	int t = heapArr[x];
			heapArr[x] = heapArr[y];
			heapArr[y] = t;
    }

    void percolateUp(int index) {
			int child =  index;
			int parent = (index-1)/2;
      
			while (heapArr[child] < heapArr[parent]) {
				swap(child, parent);
			}
    }

    void percolateDown(int index) {
      int parent = index;
			int left = (2*index) + 1;
			int right = (2*index) + 2;

      while (heapArr[parent] > heapArr[left]) {
				swap(left, parent);
			}

			while (heapArr[parent] > heapArr[right]) {
				swap(right, parent);
			}
    }

	public:
    MinHeap() {	size = -1; }

		void insert(int element) {
			size++;
			heapArr[size] = element;
			if (element < heapArr[(size-1)/2]) {
				percolateUp(size);
			}	
    }

    void deleteMin() {
      swap(0, size);
			size--;
			percolateDown(0);
		}

    int extractMin() {
			return heapArr[0];
		}

    int heapSize() {
			return size + 1;
		}

    void heapDisplay() {
			for (int i = 0; i <= size; i++) {
				cout << heapArr[i] << " ";
			}
			cout << endl;
		}

};

// in your main function, test your implementations. For example,  
int main() 
{

	MinHeap mh;
	mh.insert(44);
	mh.insert(8212);
	mh.insert(145);
	mh.insert(7);
	mh.insert(323);

	// display heap
	mh.heapDisplay();  // the output should be: 1, 3, 4, 8, 7

	// deleteMin
	mh.deleteMin();
	mh.heapDisplay();  // the output should be: 3, 7, 4, 8

	// extractMin
	cout << mh.extractMin() << endl;   // the output should be: 3

	// heapSize
	cout << mh.heapSize() << endl;   // the output should be: 4
	return 0;
}
