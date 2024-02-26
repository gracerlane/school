// Grace Lane
// 2 May 2022
// assignment2.cpp
// Purpose: In this program, there are four tasks in total:
//  1) Sums up a number's digits
//  2) Find the 5th root of a number
//  3) Egyptian Calulation- implements use of Egytian methods to divide
//  4) Finds the value of certain depths of Ramaujan's problem:
//      What is the value √(6+2√(7+3√(8+4√(9+ 5√(10+⋯)))))?


#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int DIGITS = 36;      // input used in Task 1

const double NUM = 47;       // finding the 5th root of this number in Task 2
const int GUESS = 1.0;       // used to guess 5th root in Task 2

const int DIVISOR = 6;       // used as the divisor in Task 3
const int DIVIDEND = 48;     // used as the dividend in Task 3
const int DBL = 2;           // used to double in doubleInt()- used to count down from 2 to run twice
const int HLV = 0;           // used to halve in halveInt()- used to count up from 0 to run twice

const int DEPTH = 1;         // used as the depth for Task 4

// TASK 1
int sumDigits(int x);
// returns sum of the digits in x

// TASK 2
double root5(double n, double y);
// returns the 5th root of n

// TASK 3
int egyptDivision(int c, int b);
// returns c divided by b using the Egyptian method of division
int doubleInt(int x, int y);
// returns 2*x without using any multiplication (uses addition)
int halveInt(int x, int y);
// returns x/2 without using any division (uses subtraction)

// TASK 4
double ramanujan(int depth, int y = 0);


int main() 
{
	cout << endl;
	cout << "Task 1" << endl;
	cout << "Sum of digits in " << DIGITS << ": " 
			 << sumDigits(DIGITS) << endl;
	cout << endl;

	cout << "Task 2" << endl;
	cout << "The 5th root of " << NUM << " is: " 
			 << fixed << showpoint << setprecision(4) 
			 << root5(NUM, GUESS) << endl;
	cout << endl;

	cout << "Task 3" << endl;
	cout << "Using the Egyptian method of division to divide "
			 << DIVIDEND << " by " << DIVISOR << ": " 
			 << egyptDivision(DIVIDEND, DIVISOR) << endl;
	cout << endl;

	cout << "Task 4" << endl;
	cout << "Ramanujan expression with depth of " << DEPTH 
			 << ": ";
	cout << fixed << showpoint << setprecision(4) 
			 << ramanujan(DEPTH) << endl;
	cout << "The value of this expression carried out to infinity: ";
	cout << fixed << showpoint << setprecision(4) 
			 << ramanujan(100) << endl;
	cout << endl;

	return 0;
}

// TASK 1
int sumDigits(int x)
{
	if (x == 0) {
		return 0;
	} else {
		return x % 10 + sumDigits(x / 10);
	}
}

// TASK 2
double root5(double n, double y)
{
	int y5 = y*y*y*y*y;

	if ((y5) - n <= 0.00001) {
		return root5(n, y + 0.00001);
	} else {
		return ((4)*y+(n/(y5/y)))/5;
	}
}

// TASK 3
int egyptDivision(int c, int b)
{
	int a = 1;
	int d = 0;
	while (b <= c) {
		a = doubleInt(a, DBL);
		b = doubleInt(b, DBL);
	}
	while (a > 0) {
		a = halveInt(a, HLV);
		b = halveInt(b, HLV);
		if (b <= c) {
			c -= b;
			d += a;
		}
	}
	return d;
}

int doubleInt(int x, int y)
{
	if (y == 0) {
		return 0;
	} else {
		return x + doubleInt(x, y - 1);
	}
}

int halveInt(int x, int y)
{
	if (x <= 1) {
		return y;
	}
	 else {
		return halveInt(x - 2, y + 1);
	}
}

// TASK 4
double ramanujan(int depth, int x)
{
	if (x > depth) {
		return 0;
	}
	return (x + 1) * sqrt((x + 6) + ramanujan(depth, x + 1));
}