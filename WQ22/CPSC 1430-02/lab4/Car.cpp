// Grace Lane
// Car.cpp
// Purpose: For defining the Car class's member amd constructor functions:
//  Constructor – the constructor should accept the car’s year model and make as arguments.
//   These values should be assigned to the object’s yearModel and make member variables.  
//   The constructor should also assign 0 to the speed member variables. 
//  Getter – getter functions to get the values stored in an object’s yearModel, make, and speed member variables.
//  Accelerate – the accelerate function should add 5 to the speed member variable each time it is called.
//  Brake – the brake function should subtract 5 from the speed member variable each time it is called.

#include <iostream>
#include <string>
#include "Car.h"

using namespace std;

// constructor function
Car::Car(int yr, string m) 
{
	yearModel = yr;
	make = m;
	speed = 0;
}

// returns year
int Car::getYear() const
{
	return yearModel;
}

// returns make
string Car::getMake() const
{
	return make;
}

// returns speed
int Car::getSpeed() const
{
	return speed;
}

// adds 5 to current speed
void Car::accelerate() 
{
	speed += 5;
}

// subtracts 5 from current speed
void Car::brake() 
{
	speed -= 5;
}