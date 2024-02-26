// Grace Lane
// Player.cpp
// Purpose: For defining the Player's class fuctions
//  -a setter function that sets the player selected number to a given 
//   index of the aforementioned array
//  -a getter function that returns the selected number at a given index
//  -a constructor that initializes the name of a player and the member 
//   variable that points to an integer array 
//  -a destructor that deals with memory deallocation properly

#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

// constructor function
Player::Player(string name, int size)
{
	playerName = name;
	nums = new int[size];
}

// destructor function
Player::~Player()
{
	cout << "in destructor";
	delete [] nums;
}

// sets the input number to given index of array
void Player::setNum(int index, int input)
{
	nums[index] = input;
}

// returns selected number at given index
int Player::getNum(int index) const
{
	return nums[index];
}