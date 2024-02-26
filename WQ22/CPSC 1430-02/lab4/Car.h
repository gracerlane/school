// Car.h
// Purpose: For declaring Car class
//  yearModel – an int that holds the car’s year model
//  make – a string that holds the make of the car
//  speed – an int that holds the car’s current speed

#include <iostream>
#include <string>

using namespace std;

#ifndef CAR_H
#define CAR_H
class Car {
	private:
	  int yearModel;
		string make;
		int speed;
	public:
		Car(int yr, string m);
		int getYear() const;
		string getMake() const;
		int getSpeed() const;
		void accelerate();
		void brake();
};
#endif