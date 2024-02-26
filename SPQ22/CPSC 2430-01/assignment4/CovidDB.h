// Grace Lane
// Covid.h

#include <iostream>
#include <string>
#include <vector>
#include "DataEntry.h"

using namespace std;

#ifndef COVIDDB_H
#define COVIDDB_H
class CovidDB {
	private:
		int tableSize = 17;
		vector<vector<DataEntry>> table;
		int hash(string country);       // hash the entry
	public:
		// separate chaining
		CovidDB(int m) {
			table = vector<vector<DataEntry>>(m);
			this->tableSize = m;
		}
		
		// inserts DataEntry into the hash table
		bool add(DataEntry entry);

		// returns a DataEntry with the specified country name or NULL if no such entry exisits
		DataEntry* get(string country);

		// displays the whole hash table
		void display();

		// removes the DataEntry with the specified country name
		void remove(string country);

};
#endif
