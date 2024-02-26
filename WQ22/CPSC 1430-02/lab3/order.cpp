// Grace Lane
// order.cpp
// Purpose: This program will write a class named Order that has the following member variables:
//   name – a string that holds the name of the customer of an order
//   itemID- an int that holds the ID of the item ordered by the customer
//   total - a double that holds the total amount of an order
//   status- a bool that holds the status (is active or not) of an order 
//  In addition, the class should have the following constructor and other member functions:
//   getter functions - get the values stored in an object’s name, itemID, total, and status member variables.
//   setter functions - set the name, itemID, total, and status of an Order object
//  Then the program will print out the name, ID, total, and status according to what is in the program. 

#include <iostream>
#include <iomanip>

using namespace std;

class Order
{
	private:
		string name;
		int itemId;
		double total;
		bool status;
	public:
		void setName(string n);
		void setId(int id);
		void setTotal(double ttl);
		void setStatus(bool stat);
		string getName() const;
		int getId() const;
		double getTotal() const;
		bool getStatus() const;
};

void Order::setName(string n)
{
	name = n;
}

void Order::setId(int id)
{
	itemId = id;
}

void Order::setTotal(double ttl)
{
	total = ttl;
}

void Order::setStatus(bool stat)
{
	status = stat;
}

string Order::getName() const
{
	return name;
}

int Order::getId() const
{
	return itemId;
}

double Order::getTotal() const
{
	return total;
}

bool Order::getStatus() const
{
	return status;
}

int main()
{
	Order o;
	string tempN = "Albert";
	int tempId = 100239;
	double tempTotal = 85.0;
	bool tempStatus = false;

	o.setName(tempN);
	o.setId(tempId);
	o.setTotal(tempTotal);
	o.setStatus(tempStatus);

	cout << endl;
	cout << "Name: " << o.getName() << endl;
	cout << "Item ID: " << o.getId() << endl;
	cout << "Items in order: " << o.getTotal() << endl;
	if (o.getStatus()) {
		cout << "Status of order: Active" << endl;
	} else {
		cout << "Status of order: Not Active" << endl;
	}
	cout << endl;

	return 0;
}