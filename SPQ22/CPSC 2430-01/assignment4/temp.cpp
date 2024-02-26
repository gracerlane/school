// Grace Lane
// 1 June 2022
// assignment4.cpp
// In Assignment 4, we will implement our own version of Covid Data Tracker 
//  (actually, it is just a hash table…). This assignment will practice 
//  your STL in C++ (vector), file operation in C++, hash table operations, 
//  and collision resolving. 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "CovidDB.h"
#include "DataEntry.h"

using namespace std;

const int QUIT = 0;     // for user input in the menu

// menu
int menu();

// returns vector of a string 
vector<string> split(string str, char del);

int main() {
  int choice = menu();
  CovidDB hashTable(17);

  while (choice != QUIT) {
    switch (choice) {
      case 1:     // create inital hash table
      {
        ifstream file("WHO-COVID-Data.csv");
        if(file.is_open()){
          cout << "Open file successful" << endl;
          string line;
          while(getline(file, line)){
            vector<string> result = split(line, ',');            // split the content in each line
            DataEntry oneEntry;            // wrap up all the data in the string to a DataEntry type and push it to the vector
            oneEntry.setDate(result[0]);
            oneEntry.setCountry(result[1]);
            oneEntry.setCases(stoi(result[2]));
            oneEntry.setDeaths(stoi(result[3]));
            cout << "adding   " <<	oneEntry.getDate() << " " << 	oneEntry.getCountry() << " " << 	oneEntry.getCases() 
				<< " " << 	oneEntry.getDeaths() << endl;
            hashTable.add(oneEntry);
            cout << "added" << endl;
          }
        } else {
          cout << "Open file failed" << endl;
        }
        cout << "Hash table has been made" << endl;
        cout << "Press enter to return to menu...";
				cin.get();
        break;
      }

      case 2:     // insert a new entry from the user
      {
        string line;
        cout << "Enter an entry with the format that follows: DATE,COUNTRY,CASES,DEATHS (capitalize appropriately)" << endl;
        cout << "(ex: 1/13/2020,Brazil,1,1)" << endl;
        cout << "Entry: ";
        getline(cin, line);
        vector<string> result = split(line, ',');      // split the content in each line
        DataEntry oneEntry;                            // wrap up all the data in the string to a cvsdata type and push it to the vector
        oneEntry.setDate(result[0]);
        oneEntry.setCountry(result[1]);
        oneEntry.setCases(stoi(result[2]));
        oneEntry.setDeaths(stoi(result[3]));

        cout << "adding this: ";
        cout << oneEntry.getDate() << " " << oneEntry.getCountry() << " " << oneEntry.getCases() << " " << oneEntry.getDeaths() << endl;

        hashTable.add(oneEntry);

        cout << "added" << endl << endl;

        cout << endl;
        cout << "Press enter to return to menu...";
        cin.get();
        break;
      }
      
      case 3:     // search for specified country
      {
        string search;
        cout << "Country to search for (capitalize appropriately): ";
        getline(cin, search);
        DataEntry* found = hashTable.get(search);
        if (found) {
          cout << "Data entry for " << search << ": ";
          cout << found->getDate() << "," << found->getCountry() << "," << found->getCases() << "," << found->getDeaths() << endl;
        } else {
          cout << search << " is not in the table" << endl;
        }
        cout << endl;
        cout << "Press enter to return to menu...";
				cin.get();
        break;
      }

      case 4:     // remove specified country
      {
        string input;
        cout << "Country to remove (capitalize appropriately): ";
        getline(cin, input);
        hashTable.remove(input);
        cout << endl;
        cout << "Press enter to return to menu...";
				cin.get();        
        break;
      }

      case 5:     // displays the hash table
      {
        hashTable.display();
        cout << endl;
        cout << "Press enter to return to menu...";
        cin.get();
        break;
      }

      default:
      {
        return 0;
      }
	  }
    choice = menu();
  }
  return 0;
}

int menu() {
  int choice;
  cout << endl;
  cout << "Covid Tracker" << endl;
  cout << "Please input the menu item you want: " << endl;
  cout << "1. Create the initial hash table" << endl;
  cout << "2. Add a new data entry" << endl;
  cout << "3. Get a data entry" << endl;
  cout << "4. Remove a data entry" << endl;
  cout << "5. Display hash table" << endl;
  cout << "0. Quit the system" << endl;
  cout << "Note: Please choose 1 before choosing 2, 3, or 4" << endl;
  cout << "Choice: ";
  cin >> choice;
  cin.ignore();
  cout << endl;
  return choice;
}

vector<string> split(string str, char del){
  vector<string> result;
  // declaring temp string to store the curr "word" upto del
  string temp = "";
  for(int i=0; i<(int)str.size(); i++){
      // If current char is not ',', then append it to the "word", otherwise you have completed the word, and start the next word
      if(str[i] != del){
        temp += str[i];
      } else {
          result.push_back(temp);
          temp = "";
      }
  }
  // push the last substring after the last ',' to the result
  result.push_back(temp);
  return result;
}
// Grace Lane
// CovidDB.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "CovidDB.h"
#include "DataEntry.h"

using namespace std;

int CovidDB::hash(string country) {              // hash function
	int sum = 0; 
	int c;
	for(int i = 0; i < country.size(); i++){ 
		c = (int)country[i]; 
		sum += (i + 1) * c;
	} 
	return  sum % tableSize;
}

vector<int> parseDate(string date, char delim){
	vector<int> result;
	int temp = 0;                                     // declaring temp string to store the current char up to delim
	cout << date << " size " << date.size() << endl;
	for(int i = 0; i < (int)date.size(); i++){
			if(date[i] != delim){                             // If current char is not '/', then append it to the temp, otherwise you have completed the word, and start the next word
				temp += date[i];
			} else {
				cout << "pushing back in parsing:     " << temp << endl;
				result.push_back(temp);
				temp = 0;
			}
	}
	cout << "pushing back in parsing:     " << temp << endl;
	result.push_back(temp);                               // push the last substring after the last '/' to the result
	return result;
}

bool compare(string currDate, string newDate) {          // compares the current date and the new date and returns true if the new date is greater
	cout << "comparing " << currDate << " " << newDate << endl;
	bool greater = true;
	string currMonth, currDay, currYear;
	string newMonth, newDay, newYear;
	char delim = '/';

	vector<int> date1 = parseDate(currDate, delim);
	currMonth = date1[0];
	currDay = date1[1];
	currYear = date1[2];
	
	vector<int> date2 = parseDate(newDate, delim);
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

bool CovidDB::add(DataEntry entry) {
	int index = hash(entry.getCountry());
	bool there = false;
	for (int i = 0; i < table[index].size(); i++) {                     // for the size of the vector at the index
		if (table[index][i].getCountry() == entry.getCountry()) {         // if the country exisits, there become true
			there = true;
			if (compare(table[index][i].getDate(), entry.getDate())) {      // if the new entry's date is greater than the current date, then update the data accordingly
				cout << "new is greater   " << endl;
				table[index][i].setDate(entry.getDate());
				table[index][i].setCases(table[index][i].getCases() + entry.getCases());
				table[index][i].setDeaths(table[index][i].getDeaths() + entry.getDeaths());
        cout << "updated  " <<	table[index][i].getDate() << " " << 	table[index][i].getCountry() << " " << 	table[index][i].getCases() 
				<< " " << 	table[index][i].getDeaths() << endl;

			}
		}
	}
	
	if (!there) {
		table[index].push_back(entry);
	}

	return there;
}

DataEntry* CovidDB::get(string country) {
	int searchFor = hash(country);
	for (int i = 0; i < table[searchFor].size(); i++) {
		if (table[searchFor][i].getCountry() == country) {
			return &table[searchFor][i];
		}
	}
	return nullptr;
}

void CovidDB::display() {
	cout << "Hash Table" << endl;
	for(int i = 0; i < int(table.size()); i++) {
		cout << setw(2) << i;
		for(int j = 0; j < int(table[i].size()); j++){
			cout << " -> " << table[i][j].getCountry();
		}
		cout << endl;
	}
}

void CovidDB::remove(string country) {
			int index = hash(country);            	            // get index first               
		for(int i = 0; i < table[index].size(); i++){         // traverse ith list(vector) to search 
			if(table[index][i].getCountry() == country){      	// if found, delete
				table[index].erase(table[index].begin() + i);
				cout << country << " has been deleted" << endl;
				return;
			}
		}
		cout << "No " << country << " in hash table" << endl;
}
