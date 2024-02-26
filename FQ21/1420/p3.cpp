// Grace Lane
// p3.cpp
// 11-04-2021
// Purpose: The purpose of this program is to play a game of chutes and ladders
//  with one other opponent. Each player will take turns going back and forth.
//  They will spin a number between RANGE_MIN and RANGE_MAX. Depending on the
//  number they spin, some action will be taken. This will repeat until one 
//  player reaches exactly GOAL. If they go over, their spin will not count.

#include <iostream>
#include <string>

using namespace std;

void welcome();
// displays welcome message

int spin();
// returns a valid spin value from RANGE_MIN to RANGE_MAX

int checkLocation(int location);
// returns value of chute or ladder at current location
// returns 0 if none

int takeTurn(int position, string name);
// takes turn for name
// returns position

void goodbye();


const int RANGE_MIN = 1;       // spinner min value
const int RANGE_MAX = 6;       // spinner max value
const int GOAL = 100;          // board size
const char YES = 'y';          // for user input

int main() 
{
  string userName1;            // for user input
  string userName2;
  char play = YES;
  
  int currentLocation = 0;     // placeholder for location at the end of turn
  
  int userLocation1 = 0;       // users' location at the end of each turn
  int userLocation2 = 0;  
  
  int player;                  // current player playing
  
  srand(time(0));
  
  welcome();
  cout << endl << endl;
  cout << "You will go first. What is your name? ";
  getline(cin, userName1);
  cout << "Choose an opponent. What is their name? ";
  getline(cin, userName2);
  
  cout << endl << endl;
  
  while (play == YES) {
    cout << "Press enter to play...";
    cin.get();
    userLocation1 = 0;
    userLocation2 = 0;
    player = 0;
    while(userLocation1 < GOAL && userLocation2 < GOAL) {
      if(player == 0) {
        cout << endl << endl;
        currentLocation = takeTurn(userLocation1, userName1);
        userLocation1 = currentLocation;
        player = 1;
      } else {
        cout << endl << endl;
        currentLocation = takeTurn(userLocation2, userName2);
        userLocation2 = currentLocation;
        player = 0;
      }
    }
    if(userLocation1 == GOAL) {
      cout << userName1 << " wins!" << endl;
    }
    if(userLocation2 == GOAL) {
      cout << userName2 << " wins!" << endl;
    }
    cout << endl << endl;
    cout << "Play again? (y/n) ";
    cin >> play;
    cin.ignore();
  }
  goodbye();
  return 0;
}

void welcome()
{  
  cout << endl;
  cout << "Welcome to Chutes and Ladders!" << endl;
  cout << "You must land on " << GOAL << " exactly to win!" << endl;
}

int spin()
{
  return (rand() % (RANGE_MAX - RANGE_MIN + 1)) + RANGE_MIN;
}

int checkLocation(int location)
{
  int move = location;          // new location moved to if a ladder or chute
  if(location == 1) {
	move += 37;
  } else if(location == 4) {
    move += 10;
  } else if(location == 9) {
	move += 12;
  } else if(location == 23) {
	move += 21;
  } else if(location == 28) {
    move += 56;
  } else if(location == 36) {
	move += 8;
  } else if(location == 51) {
	move += 15;
  } else if(location == 71) {
    move += 19;
  } else if(location == 80) {
	move += 20;
  } else if(location == 98) {
    move -= 20;
  } else if(location == 95) {
    move -= 20;
  } else if(location == 93) {
	move -= 20;
  } else if(location == 87) {
	move -= 63;
  } else if(location == 64) {
    move -= 4;
  } else if(location == 62) {
	move -= 43;
  } else if(location == 56) {
	move -= 3;
  } else if(location == 49) {
    move -= 38;
  } else if(location == 48) {
	move -= 22;
  } else if(location == 16) {
	move -= 10;
  } 
  return move;
}

int takeTurn(int position, string name)
{
  int moveTo;         // space the user moves to after checking for chute/ladder
  int playerSpin;     // number player spins
  int newLocation;    // adding the initial position with the player's spin
  
  cout << name << ", you are currently at " << position << "." << endl;
  cout << "Press enter to spin...";
  cin.get();
  playerSpin = spin();
  newLocation = position + playerSpin;
  cout << "You spun a(n) " << playerSpin << "." << endl;
  
  cout << "Press enter to move...";
  cin.get();
  
  cout << "You move to " << newLocation << "." << endl;
  cout << "Press enter to check for a chute or ladder...";
  cin.get();
  moveTo = checkLocation(newLocation);
  
  if(moveTo - newLocation > 0) {
	cout << "Congrats! This is a ladder! ";
	cout << "You move forward " << abs (moveTo - newLocation) << " spaces." 
         << endl;
    cout << "You are now at " << moveTo << "." << endl;
  } else if (moveTo - newLocation < 0) {
	cout << "Oh no! This is a chute! ";
	cout << "You move back " << abs (moveTo - newLocation) << " spaces." 
         << endl;
    cout << "You are now at " << moveTo << "." << endl;
  } else {
	cout << "This is neither a chute or ladder." << endl;
	cout << "You are still at " << moveTo << "." << endl;
  }
  
  if(moveTo > GOAL) { 
    cout << "Press enter to continue...";
    cin.get();
    cout << "Sorry, that is more than " << GOAL << "." << endl;
    moveTo = position;
	cout << "You are back to " << moveTo << "." << endl;
  }
  if(moveTo == GOAL) {
    cout << "Press enter to continue...";
	cin.get();
	return moveTo;
  }
  
  cout << "Press enter to continue...";
  cin.get();  
  return moveTo;
}

void goodbye() 
{
  cout << endl << endl;
  cout << "Thank you for playing! Come again!";
  cout << endl << endl;
}
