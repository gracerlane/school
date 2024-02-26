// Grace Lane
// lab17.cpp

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

int oldestPerson(const Person list[], int numElements);

int leastCoffee(const Person list[], int numElements);

void swapVal(Person& p1, Person& p2);

void selSort(Person list[], int numElements);

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
  cout << "Oldest client is: " << endl;
  printOne(clients[oldestPerson(clients, count)]);
  cout << endl << endl;
  cout << "Client who drinks the least coffee is: " << endl;
  printOne(clients[leastCoffee(clients, count)]);
  cout << endl << endl;
  
  selSort(clients, count);
  cout << "NAME             AGE  COFFEE" << endl;
  for (int i = 0; i < count; i++) {
	printOne(clients[i]);
  }
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

int oldestPerson(const Person list[], int numElements)
{
  int index = 0;
  for (int i = 1; i < numElements; i++) {
	if (list[i].age > list[index].age) {
	 index = i;
	}
  }
  return index;
}

int leastCoffee(const Person list[], int numElements)
{
  int index = 0;
  for (int i = 1; i < numElements; i++) {
	if (list[i].coffee < list[index].coffee) {
	  index = i;
	}
  }
  return index;
}

void swapVal(Person& p1, Person& p2)
{
  Person temp = p1;
  p1 = p2;
  p2 = temp;
}

void selSort(Person list[], int numElements)
{
  int index;
  for (int i = 0; i < numElements - 1; i++) {
	index = i;
	for (int j = i + 1; j < numElements; j++) {
	  if (list[j].name < list[index].name) {
		index = j;
	  }
	}
	if (index != i) {
	  swapVal(list[i], list[index]);
	}
  }
}