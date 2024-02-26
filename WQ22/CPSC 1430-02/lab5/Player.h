// Player.h
// Purpose: For declaring the Player class
//  -a member variable that holds the player name
//  -a member variable that points to an integer array which saves the 
//   selected numbers by this user. Note the array size must equal to 
//   the total number of games decided at the run-time
//  -a setter function that sets the player selected number to a given 
//   index of the aforementioned array
//  -a getter function that returns the selected number at a given index
//  -a constructor that initializes the name of a player and the member 
//   variable that points to an integer array 
//  -a destructor that deals with memory deallocation properly

#include <iostream>
#include <string>

using namespace std;

#ifndef PLAYER_H
#define PLAYER_H
class Player {
	private:
		string playerName;
		int *nums;
	public:
		Player(string name, int size);
		~Player();
		void setNum(int index, int input);
		int getNum(int index) const;
};
#endif