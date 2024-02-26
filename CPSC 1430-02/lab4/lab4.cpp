// Grace Lane
// lab4.cpp
// Purpose: 
//  This program uses the Car class, which is defined in the Car.h file
//  The Car class's member and constructor functions are defined in the 
//  Car.cpp file. This program should be compiled with those files. 
//  The program calls the accelerate function five times. After each call 
//  to the accelerate function, it gets the current speed of the car and 
//  displays it. Then, it calls the brake function five times. After 
//  each call to the brake function, it gets the current speed of the car 
//  and displays it. Then, it calls the other functions and displays the
//  values. The program does not request any information from the user 
//  of the program. It simply displays information on the screen. 

#include <iostream>
#include <string>
#include "Car.h"        // header file

using namespace std;

int main() 
{

	// declares a Car named c with the year of 2013 and the make of Ford
	Car c(2013, "Ford");    

	// calls accelerate() five times and displays speed after each call
	for (int i = 0; i < 5; i++) {
		cout << "Accelerating... ";
		c.accelerate();
		cout << "Speed: " << c.getSpeed() << endl;
	}

	cout << endl;

	// calls brake() five times and displays speed after each call
	for (int i = 0; i < 5; i++) {
		cout << "Braking... ";
		c.brake();
		cout << "Speed: " << c.getSpeed() << endl;
	}

	// calls getYear() and getMake() to display values
	cout << endl;
	cout << "Year: " << c.getYear() << endl;
	cout << "Make: " << c.getMake() << endl;
	cout << endl;

	return 0;
}
