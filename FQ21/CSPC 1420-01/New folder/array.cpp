// exam review
// lab2
// array.cpp

#include <iostream>

using namespace std;

int main()
{
	int row;
	int col;
	
	int num;
	
	int rowTotal = 0;
	int colTotal = 0;
	
	cout << "Input row" << endl;
	cin >> row;
	// cout << endl;
	
	cout << "Input col" << endl;
	cin >> col;
	// cout << endl;
	
	// int arr[row][col];
	// int* *arr = new int* [row];
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << "Input number at row " << i + 1 << " col " << j + 1 << endl;
			cin >> num;
			arr[i][j] = num;
		}
	}
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr[i][j];
		}
		cout >> endl;
	}
	// cout << endl;
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			rowTotal += arr[i][j];
		}
		cout << "Sum of row " << i + 1 << " is " << rowTotal << endl;
		// rowTotal = 0;
	}
	
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			colTotal += arr[j][i];
		}
		cout << "Sum of col " << i + 1 " is " << colTotal << endl;
		// colTotal = 0;
	}
	cout << endl << endl;
	
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			delete [] arr;
		}
	}	
	arr = nullptr;
	return 0;
}