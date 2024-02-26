// Grace Lane
// lab14.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Person
{
  string name;
  int age;
  int coffee;
};

const int MAX = 150;
const int NAME_LENGTH = 15;
const int AGE_LENGTH = 4;
const int COFFEE_LENGTH = 4;
const string FILENAME = "/home/fac/sreeder/class/cs1420/lab14input.dat";

void printOne(Person p);

double average(const Person list[], int numElements);

int totalCups(const Person list[], int numElements);

int main()
{
  Person clients[MAX];
  int count = 0;
  ifstream input;
  
  cout << endl << endl;
  
  input.open(FILENAME);
  if (input.fail()) {
    cout << "file error... exiting program... press enter...";
	cin.get();
	cout << endl << endl;
	return 0;
  }
	  
  while(input >> clients[count].name) {
	input >> clients[count].age >> clients[count].coffee;
	count++;
  }
  input.close();
   
  cout << "NAME             AGE  COFFEE" << endl;
  for (int i = 0; i < count; i++) {
	printOne(clients[i]);
  }
  
  cout << endl << endl;
  cout << "Average age is: " << average(clients, count) << endl;
  cout << "Total coffee is: " << totalCups(clients, count) << endl;
  cout << endl << endl;
 
  return 0;
}

void printOne(Person p) {
  cout << left
       << setw(NAME_LENGTH) << p.name
	   << right
       << setw(AGE_LENGTH) << p.age
	   << setw(COFFEE_LENGTH) << p.coffee << endl;
}

double average(const Person list[], int numElements)
{
  double avg = 0;
  for (int i = 0; i < numElements; i++) {
	avg += list[i].age;
  }
  return avg / numElements;
}

int totalCups(const Person list[], int numElements)
{
  int total = 0;
  for (int i = 0; i < numElements; i++) {
	total += list[i].coffee;
  }
  return total;
}