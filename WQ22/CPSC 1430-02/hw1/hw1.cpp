// Grace Lane
// hw1.cpp
// Purpose: The purpose of this porgram is to take a .txt file that 
//  contains COVID data of each state in the US and then does one of the
//  following that the user chooses:
//   -Display a menu of options to the user that include:
//  	 -Allow the user to display the COVID info of all states
//  	 -Allow the user to display the COVID info of the state that has the 
//  	  most cases
// 	   -Allow the user to display the COVID info of the state that has the 
//   		most deaths
// 		 -Allow the user to display some basic COVID statistics of all states
//  	 -Allow the user to quit your program

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct State            // struct to store state information
{
	string date;
	string name;
	string fips;
	int cases;
	int deaths;
};

const int STATES = 1;            // for menu options
const int CASES = 2;
const int DEATHS = 3;
const int STATS = 4;
const int QUIT = 5;

const int STATES_WIDTH = 25;     // for printing purposes
const int CASES_WIDTH = 15;
const int DEATHS_WIDTH = 15;

int menu();
// prints menu choices and asks user to choose
// returns user's choice

void displayStates(const State *data, int numElements);
// prints out all of the states names, cases, and deaths

void mostCases(const State data[], int numElements);
// prints state with the most cases

void mostDeaths(const State data[], int numElements);
// prints state with the most deaths

void stats(const State data[], int numElements);
// prints basic COVID stats for all states

int main()
{	
	ifstream input;            // for file input
	string inputFile;          // for file input
	int count = 0;             // to count the number of states read into the array
	string stateInfo;          // to find each line in the file
	int numLines = 0;          // to count the number of lines in the file

	int choice = 0;            // for menu selection

	cout << endl;
	cout << "Please enter the input file name: ";
	getline(cin, inputFile);
  
	input.open(inputFile);

	if (input.fail()) {
		cout << endl;
		cout << "file error... exiting program... press enter...";
		cin.get();
		cout << endl;
		return 0;
  }

	if (input.is_open()) {                 // checks the file is open and counts the number of lines
		while (input.peek() != EOF) {
			getline(input, stateInfo);
			numLines++;
		}
		input.close();
	}

	input.open(inputFile);

	State* data = new State[numLines];     // dynamically allocates an array to store states

	while (count < numLines) {                    // reads the file and assigns to the array
		getline(input, data[count].date, ',');
		getline(input, data[count].name, ',');
		getline(input, data[count].fips, ',');
		input >> data[count].cases;
		input.ignore();
		input >> data[count].deaths;
		input.ignore();
		count++;
	}
	input.close();

	choice = menu();                     // calls menu for user to choose which option to see
	while (choice != QUIT) {
		if (choice == STATES) {
			displayStates(data, count);
		} else if (choice == CASES) {
			mostCases(data, count);
		} else if (choice == DEATHS) {
			mostDeaths(data, count);
		} else if (choice == STATS) {
			stats(data, count);
		} else {
			return 0;
		}
		choice = menu();                   // calls menu again to allow the user to choose a different option
	} 

	delete [] data;        // deletes the dynamically allocated array to free up space
	return 0;
}

// prints menu and returns user's choice
int menu() 
{
	int menuInput;
	
	cout << endl;
	cout << "************Menu************" << endl;
	cout << STATES << ". Display the COVID info of all states" << endl;
	cout << CASES << ". Display the COVID info of the state that has the most cases" << endl;
	cout << DEATHS << ". Display the COVID info of the state that has the most deaths" << endl;
	cout << STATS << ". Display the statistics of all states" << endl;
	cout << QUIT << ". Exit the program" << endl;
	cout << "Enter your choice: ";
	cin >> menuInput;
	cout << endl;

	return menuInput;
}

// prints out states and their cases and deaths
void displayStates(const State *data, int numElements)
{
	cout << setw(STATES_WIDTH) << "**States**";
	cout << setw(CASES_WIDTH) << "**Cases**";
	cout << setw(DEATHS_WIDTH) << "**Deaths**";
	cout << endl;
	for (int i = 0; i < numElements; i++) {
		cout << setw(STATES_WIDTH) << data[i].name
				 << setw(CASES_WIDTH) << data[i].cases
				 << setw(DEATHS_WIDTH) << data[i].deaths << endl;
	}
}

// finds the state with the most cases and prints it out
void mostCases(const State data[], int numElements)
{
	int index = 0;
  for (int i = 1; i < numElements; i++) {
		if (data[i].cases > data[index].cases) {
	 		index = i;
		}
  }
	cout << data[index].name << " has the most cases: " << data[index].cases << endl;
}

// finds the state with the most deaths and prints it out
void mostDeaths(const State data[], int numElements)
{
	int index = 0;
  for (int i = 1; i < numElements; i++) {
		if (data[i].deaths > data[index].deaths) {
	 		index = i;
		}
  }
	cout << data[index].name << " has the most deaths: " << data[index].deaths << endl;
}

// prints stats for all states
void stats(const State data[], int numElements)
{
	int totalCases = 0;
	int totalDeaths = 0;
	double avgRate;

	for (int i = 0; i < numElements; i++) {         // finds the total cases of all the states
		totalCases += data[i].cases;
	}
	cout << "(a) There are " << totalCases << " cases in total, " 
			 << (totalCases/numElements) << " on average" << endl;

	for (int i = 0; i < numElements; i++) {         // finds the total deaths of all the states
		totalDeaths += data[i].deaths;
	}
	cout << "(b) There are " << totalDeaths << " deaths in total, " 
			 << (totalDeaths/numElements) << " on average" << endl;

	for (int i = 0; i < numElements; i++) {         // finds the average death rate for all states
		avgRate = ((double) totalDeaths/ (double) totalCases) * 100;
	}
	cout << "(c) The average death rate for all states is " << fixed << setprecision(2) << avgRate << "%" << endl;

	int index = 0;         // for looking at the values in the array
	int num = 0;           // for progressing through the array
	double first;          // for comparing death rates
	double second;         // for comparing death rates
	double highestRate;    // highest death rate

  for (int i = 1; i < numElements; i++) {
		if (data[num].deaths > 100) {
			first = (((double) data[i].deaths/ (double) data[i].cases) * 100);
			second = (((double) data[index].deaths/ (double) data[index].cases) * 100);
			if (first > second) {
				index = i;
			}
			num++;
		}
  }
	highestRate = (((double) data[index].deaths/ (double) data[index].cases) * 100);
	cout << "(d) Among all states that have more than 100 deaths, " << data[index].name
			 << " has the highest death rate of " << highestRate << "%" << endl;
}