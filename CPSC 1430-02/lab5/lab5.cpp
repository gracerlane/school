// Grace Lane
// lab5.cpp
// Purpose: 
//  This program uses the Car class, which is defined in the Car.h file
//  The Car class's member and constructor functions are defined in the 
//  Car.cpp file. This program should be compiled with those files. 

#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

int main(int argc, char *argv[])
{
	int totalGames;
	string name1;
	int num1;
	int bigger1 = 0;
	string name2;
	int num2;
	int bigger2 = 0;

	cout << "Please enter the total number of games: ";
	cin >> totalGames;
	
	cout << endl;
	cout << "Please enter the name of first player: ";
	cin >> name1;
	Player player1(name1, totalGames);
	
	for (int i = 0; i < totalGames; i++) {
		cout << "Please enter a number at index " << i + 1
				 << " for player " << name1 << ": ";
		cin >> num1;
		player1.setNum(i, num1);
	}

	cout << "Player " << name1 << " selected the following numbers: ";
	for (int i = 0; i < totalGames; i++) {
		cout << player1.getNum(i) << " ";
	}

	cout << endl << endl;
	cout << "Please enter the name of second player: ";
	cin >> name2;
	Player player2(name2, totalGames);

	for (int i = 0; i < totalGames; i++) {
		cout << "Please enter a number at index " << i + 1
				 << " for player " << name2 << ": ";
		cin >> num2;
		player2.setNum(i, num2);
	}
	
	cout << "Player " << name2 << " selected the following numbers: ";
	for (int i = 0; i < totalGames; i++) {
		cout << player2.getNum(i) << " ";
	}

	cout << endl;
	for (int i = 0; i < totalGames; i++) {
		if (player1.getNum(i) > player2.getNum(i)) {
			bigger1++;
		} else if (player2.getNum(i) > player1.getNum(i)){
			bigger2++;
		}
	}

	cout << endl;
	if (bigger1 > bigger2) {
		cout << name1 << " Won" << endl;
	} else if (bigger2 > bigger1) {
		cout << name2 << " Won" << endl;
	} else {
		cout << "Draw";
	}

	return 0;
}