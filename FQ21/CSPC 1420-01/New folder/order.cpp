// exam review
// lab3
// order.cpp

#include <iostream>
#include <string>

using namespace std;


class Order {
	private:
		string name;
		int itemID;
		double total;
		bool status;
	
	public:
		void setName(string);
		void setID(int);
		void setTotal(double);
		void setStatus(bool);
		
		string getName() const;
		int getID() const;
		double getTotal() const;
		bool getStatus() const;
};

void Order::setName(string n)
{
	cout << "Setting name to " << n << endl;
	name = n;
}

void Order::setID(int id)
{
	cout << "Setting ID to " << id << endl;
	itemID = id;
}

void Order::setTotal(double t)
{
	cout << "Setting total to " << t << endl;
	total = t;
}

void Order::setStatus(bool s)
{
	cout << "Setting status to " << s << endl;
	status = s;
}

string Order::getName() const
{
	return name;
}

int Order::getID() const
{
	return itemID;
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
	int stat;
	Order o;
	o.setName("Bob");
	o.setID(124421);
	o.setTotal(45);
	o.setStatus(true);
	
	cout << "Name: " << o.getName() << endl;
	cout << "ID: " << o.getID() << endl;
	cout << "Total: " << o.getTotal() << endl;
	if(o.getStatus()) {
		cout << "Status: active" << endl;
	} else {
		cout << "Status: not active" << endl;
	}
	
	return 0;
}