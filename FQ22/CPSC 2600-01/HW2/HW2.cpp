// Grace Lane
// 16 October 2022
// HW2.cpp
// Purpose: Welcome to HW 2: programming!  Given subsets A and B of a universal
//  set with 10 elements {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, we will use bit 
//  strings to find A U B, A ∩ B, and A – B. Users will be asked to input 
//  values to each set. For example, if the user enters 1, 2, 6, the bit string
//  will display from left to right and display 0110001000.

#include <iostream>

using namespace std;

const int STOP = -1;       // the "stopping number" to get out of the while loop when receiving user input

int main()
{
	cout << endl;
	cout << "Welcome to HW2: Programming!" << endl << endl;
  cout << "Given subsets A and B of a universal set with 10 elements" << endl; 
	cout << "{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, we will use bit strings to find A U"
			 << "B, A ∩ B, and A – B." << endl;
	cout << "Users will be asked to populate each set. For example, if the user"
			 << "enters 1, 2, 6, the bit " << endl;
	cout << "string will display from left to right and display 0110001000." 
			 << endl;
	cout << endl;
	
	int setA = 0;             																					 		    // a variable to save the bit vector of set A
	int userInput;             																							    // a variable to save the user input
	while (userInput != STOP) {																					  			// loop to continually read user input and construct the bit vector of set A until encountering an invalid number to stop (e.g. -1)
		cout << "Please input a number for set A (or -1 to stop): ";            	
		cin >> userInput;                                                         // takes in user input
		setA |= (1 << userInput);                                                 // shift left userInput number of times and place a 1
	}
	cout << endl;

	int setB = 0;              																					   		  // a variable to save the bit vector of set B
	userInput = 0;																												  		// resets userInput to pass to loop
	while (userInput != STOP) {																							  	// loop to continually read user input and construct the bit vector of set B until encountering an invalid number to stop (e.g. -1)
		cout << "Please input a number for set B (or -1 to stop): ";            	
		cin >> userInput;                                                         // takes in user input
		setB |= (1 << userInput);                                                 // shift left userInput number of times and place a 1
	}
	cout << endl;

	// prints out setA
	cout << "Set A:        ";
	for (int i = 0; i < 10; i++) {
		cout << ((setA >> i) & 1);																		  					
	}
	cout << endl;

	// prints out setB
	cout << "Set B:        ";
	for (int i = 0; i < 10; i++) {
		cout << ((setB >> i) & 1);																			  				
	}
	cout << endl << endl;

	// prints out Union of A and B
	cout << "Union:        ";
	for (int i = 0; i < 10; i++) {
		cout << (((setA >> i) & 1) | ((setB >> i) & 1));                       
	}
	cout << endl;

	// prints out Intersection of A and B
	cout << "Intersection: ";
	for (int i = 0; i < 10; i++) {
		cout << (((setA >> i) & 1) & ((setB >> i) & 1));                        
	}
	cout << endl;

	// prints out Difference of A and B
	cout << "Difference:   ";
	for (int i = 0; i < 10; i++) {
		cout << (((setA >> i) & 1) & ~((setB >> i) & 1));                        
	}
	cout << endl << endl;

	return 0;
}



