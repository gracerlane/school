// Grace Lane
// 15 April 2022
// new_bico.cpp
// Purpose: This program will accept two integers from the user. The first will
//  be the degree of the binomial. The second will be the index of the 
//  coefficient. Then, the program will print out the result based on the user's
//  chosen integers.

#include <iostream>

using namespace std;

int new_bico(int x, int y);
// takes the degree(x) and the index(y)
// returns the i-th coefficient of binomial (x+y)^n


int main()
{
	cout << "The result is: " << new_bico(3, 2) << endl;     // calls the bico() function with the user inputted value
	return 0;
}

int new_bico(int x, int y)
{
	if (y == 0 || y == x) {
		return 1;
	} else {
		return new_bico(x-1, y-1) + new_bico(x-1,y);
	}
}