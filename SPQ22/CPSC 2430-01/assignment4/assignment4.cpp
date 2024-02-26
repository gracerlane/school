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
      case 1:                // create inital hash table based on the file
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
            hashTable.add(oneEntry);
          }
        } else {
          cout << "Open file failed" << endl;
        }
        cout << "Hash table has been made" << endl;
        cout << "Press enter to return to menu...";
				cin.get();
        break;
      }

      case 2:                // insert a new entry from the user
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
        hashTable.add(oneEntry);
        cout << "The table has been updated accordingly" << endl;
        cout << endl;
        cout << "Press enter to return to menu...";
        cin.get();
        break;
      }
      
      case 3:                // search for specified country and print the data for that country
      {
        string search;
        cout << "Country to search for (capitalize appropriately): ";
        getline(cin, search);
        DataEntry* found = hashTable.get(search);           // calls get() on the specified country
        if (found) {
          cout << "Data entry for " << search << ": " << endl;
          cout << found->getDate() << ", " << found->getCountry() << ", " << found->getCases() << ", " << found->getDeaths() << endl;
        } else {
          cout << search << " is not in the table" << endl;
        }
        cout << endl;
        cout << "Press enter to return to menu...";
				cin.get();
        break;
      }

      case 4:                // remove specified country
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

      case 5:                // displays the hash table
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
  string temp = "";                            // declaring temp string to store the current "word" upto del
  for (int i=0; i<(int)str.size(); i++) {      // If current char is not '/', then append it to the "word", otherwise you have completed the word, and start the next word
    if (str[i] != del){
      temp += str[i];
    } else {
        result.push_back(temp);
        temp = "";
    }
  }
  result.push_back(temp);                      // push the last substring after the last '/' to the result
  return result;
}