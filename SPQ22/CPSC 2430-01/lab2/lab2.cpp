// Grace Lane
// 15 April 2022
// lab2.cpp
// Purpose: This program will call the old_bico() function that uses iteration 
//  and calculate the runtime. Then it will call the new_bico() function
//  that uses recursion and calculate the runtime. Then it will compare the two
//  runtimes.

#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int old_bico(int x, int y);
// takes the degree(x) and the index(y)
// returns the i-th coefficient of binomial (x+y)^n
// uses iteration

int new_bico(int x, int y);
// takes the degree(x) and the index(y)
// returns the i-th coefficient of binomial (x+y)^n
// uses recursion



int main()
{
    
    // set a clock before the program executes
    auto start = high_resolution_clock::now();
    
    // program execution
    // cout << "result: " << old_bico(5,2) << endl;
		// cout << "result: " << old_bico(10,5) << endl;
		// cout << "result: " << old_bico(40,20) << endl;

		// cout << "result: " << new_bico(3,2) << endl;
		// cout << "result: " << new_bico(12,6) << endl;
		// cout << "result: " << new_bico(30,15) << endl;
    

		// cout << "result: " << old_bico(4,2) << endl;
		// cout << "result: " << old_bico(15,7) << endl;
		// cout << "result: " << old_bico(35,17) << endl;

		// cout << "result: " << new_bico(4,2) << endl;
		// cout << "result: " << new_bico(15,7) << endl;
		// cout << "result: " << new_bico(35,17) << endl;

    // set a clock after the program executes
    auto stop = high_resolution_clock::now();
    
    // get the execution time by calculating the difference between two clocks
    auto duration = duration_cast<nanoseconds>(stop - start);
    
    // output the duration
    cout << "TIME: " << duration.count() << endl;

    return 0;
}


int old_bico(int x, int y)
{
	int degree = x;                  
	int targetIndex = y;
	int arr[degree+1][degree+1];            // creates a 2D array with row and column size of the degree of binomial

	for (int rowIndex = 0; rowIndex <= degree; rowIndex++) {        // outer for loop to iterate through the row(degrees)
		for (int i = 0; i <= rowIndex; i++) {                         // inner for loop to iterate through the column(coefficients)
			if (rowIndex == i || i == 0) {                              // if the rowIndex is at the end or this is the first iteration
				arr[rowIndex][i] = 1;
			} else {
				arr[rowIndex][i] = arr[rowIndex - 1][i] + arr[rowIndex - 1][i - 1];     // using Pascal's Triangle equation that adds up the two values above to get the next values
			}
			// cout << arr[rowIndex][i] << " ";
		}
		// cout << endl;
	}
	return arr[degree][targetIndex];           // returns the coefficient at the desired targetIndex
}

int new_bico(int x, int y)
{
	if (y == 0 || y == x) {
		return 1;
	} else {
		return new_bico(x-1, y-1) + new_bico(x-1,y);
	}
}