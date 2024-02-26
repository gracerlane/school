// Grace Lane
// 8 April 2022
// bico.cpp
// Purpose: This program will accept two integers from the user. The first will
//  be the degree of the binomial. The second will be the index of the 
//  coefficient. Then, the program will print out the result based on the user's
//  chosen integers.

#include <iostream>

using namespace std;

int bico(int x, int y);
// takes the degree(x) and the index(y)
// returns the i-th coefficient of binomial (x+y)^n


int main()
{
	int deg, index;        // for user input
	
	cout << "Please input the degree of the binomial: ";
	cin >> deg;
	cout << "Please input the index of the coefficient: ";
	cin >> index;
	while (index > deg || index < 0) {                            // if the user inputs a value that is invalid then 
		cout << "Invalid." << endl;                                 // it will ask for a new one until the user inputs a valid value
		cout << "Please input the index of the coefficient: ";
		cin >> index;
	}
	cout << "The result is: " << bico(deg, index) << endl;     // calls the bico() function with the user inputted value
	return 0;
}

int bico(int x, int y)
{
	int degree = x;                  
	int targetIndex = y;
	int arr[degree][degree];            // creates a 2D array with row and columnsize of the degree of binomial
	
	for (int rowIndex = 0; rowIndex <= degree; rowIndex++) {        // outer for loop to iterate through the row(degrees)
		for (int i = 0; i <= rowIndex; i++) {                         // inner for loop to iterate through the column(coefficients)
			if (rowIndex == i || i == 0) {                              // if the rowIndex is at the end or this is the first iteration
				arr[rowIndex][i] = 1;
			} else {
				arr[rowIndex][i] = arr[rowIndex - 1][i] + arr[rowIndex - 1][i - 1];       // using Pascal's Triangle equation that adds up the two values above to get the next values
			}
		}
	}
	return arr[degree][targetIndex];           // returns the coefficient at the desired targetIndex


}