// Grace Lane
// CovidDB.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "CovidDB.h"
#include "DataEntry.h"

using namespace std;

int CovidDB::hash(string country) {                     // hash function
	int sum = 0; 
	int c;
	for(int i = 0; i < country.size(); i++){ 
		c = (int)country[i]; 
		sum += (i + 1) * c;
	} 
	return  sum % tableSize;
}

vector<int> parseDate(string date, char delim){         // separates the date by the month, day, and year
	vector<int> result;
	int temp = 0;                                         // declaring temp int to store the value of the date
	for(int i = 0; i < (int)date.size(); i++){
			if(date[i] != delim){                             // If current char is not '/', then add it to the temp, otherwise you have completed the word, and start the next word
				temp += date[i];
			} else {
				result.push_back(temp);
				temp = 0;
			}
	}
	result.push_back(temp);                               // push the last int after the last '/' to the result
	return result;
}

bool compare(string currDate, string newDate) {         // compares the current date and the new date and returns true if the new date is greater
	bool greater = true;
	string currMonth, currDay, currYear;
	string newMonth, newDay, newYear;
	char delim = '/';

	vector<int> date1 = parseDate(currDate, delim);       // parse the current date and assign values accordingly
	currMonth = date1[0];
	currDay = date1[1];
	currYear = date1[2];

	vector<int> date2 = parseDate(newDate, delim);        // parse the new date and assign values accordingly
	newMonth = date2[0];
	newDay = date2[1];
	newYear = date2[2];

	if (newYear > currYear) {
		return greater;
	}

	if (newMonth > currMonth) {
		return greater;
	}

	if (newDay > currDay) {
		return greater;
	}

	return false;
}

bool CovidDB::add(DataEntry entry) {                                  // adds entries to the table
	int index = hash(entry.getCountry());
	bool there = false;
	for (int i = 0; i < table[index].size(); i++) {                     // for the size of the vector at the index
		if (table[index][i].getCountry() == entry.getCountry()) {         // if the country exisits, there become true
			there = true;
			if (compare(table[index][i].getDate(), entry.getDate())) {      // if the new entry's date is greater than the current date, then update the data accordingly
				table[index][i].setDate(entry.getDate());
				table[index][i].setCases(table[index][i].getCases() + entry.getCases());
				table[index][i].setDeaths(table[index][i].getDeaths() + entry.getDeaths());
			}
		}
	}
	
	if (!there) {
		table[index].push_back(entry);
	}

	return there;
}

DataEntry* CovidDB::get(string country) {               // returns a pointer to the DataEntry with the specified country, returns nullptr if not found
	int searchFor = hash(country);
	for (int i = 0; i < table[searchFor].size(); i++) {
		if (table[searchFor][i].getCountry() == country) {
			return &table[searchFor][i];
		}
	}
	return nullptr;
}

void CovidDB::display() {                               // display the whole hash table
	cout << "Hash Table" << endl;
	for(int i = 0; i < int(table.size()); i++) {
		cout << setw(2) << i;
		for(int j = 0; j < int(table[i].size()); j++){
			cout << " -> " << table[i][j].getCountry();
		}
		cout << endl;
	}
}

void CovidDB::remove(string country) {                  // removes the DataEntry of the specified country
	int index = hash(country);            	              // get index first               
	for(int i = 0; i < table[index].size(); i++){         // traverse vector at the index
		if(table[index][i].getCountry() == country){      	// if found, delete
			table[index].erase(table[index].begin() + i);
			cout << country << " has been deleted" << endl;
			return;
		}
	}
	cout << "No " << country << " in hash table" << endl;
}
