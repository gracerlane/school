// Grace Lane
// DataEntry.h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef DATAENTRY_H
#define DATAENTRY_H
class DataEntry{
	private:
		string date;
		string country;
		int c_cases;
		int c_deaths;
	public:
	  // setter and getter functions
		void setDate(string d) { date = d;	}
		void setCountry(string c) {	country = c;	}
		void setCases(int c) { c_cases = c;	}
		void setDeaths(int d) { c_deaths = d; }
		
		string getDate() const { return date;	}
		string getCountry() const {	return country;	}
		int getCases() const { return c_cases; }
		int getDeaths() const { return c_deaths; }
};
#endif