// Grace Lane
// array.cpp
// Purpose: The purpose of this program is to create a two-dimensional
//  array of integers according to the user’s request. The program asks
//  the user for the number of rows and columns for the array, and all 
//  the elements of the array. Then, it prints the array contents along 
//  with the sum of each row, and the sum of each column.

#include <iostream>
#include <iomanip>

using namespace std;

const int COL_WIDTH = 4;

int main()
{
	int row, col, rowTotal;

	cout << "Input row" << endl;
	cin >> row;

	cout << "Input col" << endl;
	cin >> col;

	arr = new int[row][col];

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cout << "Input number at row " << i << " col " << j << endl;
			cin >> arr[i][j];
			cout << endl;
		}
	}

	for (int i = 1; i <= row; i++) {
		for (int j = 1; j <= col; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;


	delete [] arr;
	arr = nullptr;


	return 0;
}