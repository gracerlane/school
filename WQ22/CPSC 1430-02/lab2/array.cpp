// Grace Lane
// array.cpp
// Purpose: The purpose of this program is to create a two-dimensional
//  array of integers according to the user’s input. The program asks
//  the user for the number of rows and columns for the array, then all 
//  the elements of the array. Then, it prints the array contents along 
//  with the sum of each row, and the sum of each column.

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
	int row, col, rowTotal, colTotal = 0;

	cout << "Input row" << endl;
	cin >> row;
	cout << endl;

	cout << "Input col" << endl;
	cin >> col;
	cout << endl;

	int* *arr = new int*[row];

  for (int i = 0; i < row; i++) {
		arr[i] = new int[col];
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << "Input number at row " << i + 1 << " col " 
			     << j + 1 << endl;
			cin >> arr[i][j];
			cout << endl;
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			rowTotal += arr[i][j];
		}
		cout << "Sum of row " << i + 1 << " is " << rowTotal << endl;
	  rowTotal = 0;
	}

	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			colTotal += arr[j][i];
		}
		cout << "Sum of col " << i + 1 << " is " << colTotal << endl;
	  colTotal = 0;
	}
	cout << endl;

	delete [] arr;
	arr = nullptr;

	return 0;
}