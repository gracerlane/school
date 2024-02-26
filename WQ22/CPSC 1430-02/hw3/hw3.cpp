// Grace Lane
// hw3.cpp
// Purpose: This program uses the FancyList class, which is defined 
//  in the FancyList.h file. The FancyList class's member and constructor
//  functions are defiend in the FancyList.cpp file. This program should
//  be compiled with those files.
//  The program displays a menu with the following options:
//   -Create a list: user will be asked to type some numbers, for which 
//    your program will create a list and append each of the typed numbers 
//    into the list.  
//   -Display the list: your program will display the created list
//   -Reverse the list: your program will reverse the list. For example, 
//    if the original list order is 1->2->3->4, the reversed list will be 
//    4->3->2->1. Note that here your program should reverse the list 
//    permanently instead of just printing the list in the reverse order.
//   -Delete the n-th node from the end of the list: your program will 
//    first ask the user to type a number, say n, and then remove the n-th 
//    node from the current list. You can assume that user-typed number n 
//    will always be valid. For example, if the current list is 1->2->3->4->5 
//    and the user typed 1 as n, your program will remove the first node 
//    from the end of the list, which makes the list becomes (permanently) 
//    1->2->3->4; if the user decided to remove one more node and typed 4 as 
//    n, your program will remove the fourth node from the end of the list, 
//    which makes the list becomes (permanently) 2->3->4. 

#include <iostream>
#include <string>
#include "FancyList.h"

using namespace std;

const int CREATE = 1;
const int DISPLAY = 2;
const int REVERSE = 3;
const int DELETE = 4;
const int QUIT = 5;

const string STOP = "x";

int menu();
// returns user choice for menu options

int main(int argc, char *argv[])
{
	int choice;
	string input;
	int num;
	int nthNode;
	int valid;

	FancyList list;

	choice = menu();
	while (choice != QUIT) {
		if (choice == CREATE) {
			while (true) {
				cout << "Type a number for appending (type " << STOP << " to stop): ";
				cin >> input;
				if (input == STOP) {
					break;
				}
				else {
					num = atoi(input.c_str());
					list.append(num);
				}
			}
			cout << endl;
		} else if (choice == DISPLAY) {
			cout << "Current list is: ";
			list.printList();
		} else if (choice == REVERSE) {
			list.reverse();
			cout << "Current list after reversing is: ";
			list.printList();
		} else if (choice == DELETE) {
			cout << "Delete n-th node from the end of the list, your n is: ";
			cin >> nthNode;
			valid = list.deleteNode(nthNode);
			if (valid == 1) {               // if deleted the node successfully
				cout << "Current list after deleting the " << nthNode << "-th node from the end is: ";
				list.printList();
			} else if (valid == -1) {       // if user inputed number was invalid
				cin.ignore();
				cout << "Invalid number... press enter to return to menu...";
				cin.get();
				cout << endl;
			} else if (valid == 0) {        // if empty list
				cout << "Empty list";
				cout << endl << endl;
			}
		} else {
			return 0;
		}
		choice = menu();
	}

	return 0;
}

int menu() 
{
	int menuInput;
	
	cout << "********* FancyList Menu *********" << endl;
	cout << CREATE << ". Create a list" << endl;
	cout << DISPLAY << ". Display the list" << endl;
	cout << REVERSE << ". Reverse the list" << endl;
	cout << DELETE << ". Delete the n-th node from the end of the list" << endl;
	cout << QUIT << ". Exit the program" << endl << endl;
	cout << "Enter your choice: ";
	cin >> menuInput;

	return menuInput;
}