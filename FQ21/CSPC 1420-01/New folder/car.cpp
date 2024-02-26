// exam review
// lab4
// car.cpp

#include <iostream>
#include <string>

using namespace std;

class Car {
	private:
		int yearModel;
		string make;
		int speed;
	public:
		Car(int, string);
		int getYear() const;
		string getMake() const;
		int getSpeed() const;
		void accelerate();
		void brake();
};

Car::Car(int yr, string m)
{
	yearModel = yr;
	make = m;
	speed = 0;
}

int Car::getYear() const
{
	return yearModel;
}

string Car::getMake() const
{
	return make;
}

int Car::getSpeed() const
{
	return speed;
}

void Car::accelerate()
{
	speed += 5;
}

void Car::brake()
{
	speed -= 5;
}

int main()
{
	Car c(2013, "Ford");
	
	cout << "Year: " << c.getYear() << endl;
	cout << "Make: " << c.getMake() << endl;
	
	for (int i = 0; i < 5; i++) {
		cout << "accelerating..." << endl;
		c.accelerate();
		cout << "speed: " << c.getSpeed() << endl;
	}
	
	for (int i = 0; i < 5; i++) {
		cout << "braking..." << endl;
		c.brake();
		cout << "speed: " << c.getSpeed() << endl;
	}

	
	return 0;
}