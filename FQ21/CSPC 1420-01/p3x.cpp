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


const int RANGE_MIN = 1;            // spinner min value
const int RANGE_MAX = 6;            // spinner max value
const int GOAL = 20;                // board size
const char YES = 'y';
const int PLAYER_MIN = 2;           // min number of players
const int PLAYER_MAX = 6;           // max number of players

int main() 
{
  string players[PLAYER_MAX];       // user input
  char play = YES;
  int currentLocation = 0;
  int numPlayers;
  
  int playerLocation[PLAYER_MAX];   // array of player locations
  int board[GOAL];                  // array of the board
  
  int player;                       // current player playing
  
  bool noneAtGoal = true;           // true if no player has won
  
  srand(time(0));
  
  for (int i = 0; i < GOAL; i++) {
  if(board[i] == 1) {
	board[i] = 37;
  } else if(board[i] == 4) {
	board[i] = 10;
  } else if(board[i] == 9) {
	board[i]= 12;
  } else if(board[i] == 23) {
	board[i] += 21;
  } else if(board[i] == 28) {
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
  
  welcome();
  cout << endl << endl;
  cout << "How many people are playing? (" << PLAYER_MIN << " to " 
         << PLAYER_MAX << ") ";
  cin >> numPlayers;
  cin.ignore();
  while (numPlayers < PLAYER_MIN || numPlayers > PLAYER_MAX) {
    cout << endl << endl;
	cout << "Please enter a value between " << PLAYER_MIN << " and "
	     << PLAYER_MAX << "." << endl;
    cout << "How many people are playing? (" << PLAYER_MIN << " to " 
         << PLAYER_MAX << ") ";
    cin >> numPlayers;
    cin.ignore();
  }
  players[numPlayers];
  for (int i = 0; i < numPlayers; i++) {
    cout << "Please enter player " << i + 1 << " name: ";
    getline(cin, players[i]);
  }
  
  while (play == YES) {
	cout << endl << endl;
    cout << "Press enter to play...";
    cin.get();
	for (int i = 0; i < numPlayers; i++) {
	playerLocation[i] = 0;
    }
	noneAtGoal = true;
    while (noneAtGoal == true) {
	  for (int j = 0; j < numPlayers; j++) {
        cout << endl << endl;
        currentLocation = takeTurn(playerLocation[j], players[j]);
        playerLocation[j] = currentLocation;
		if (playerLocation[j] == GOAL) {
          cout << players[j] << " wins!" << endl;
	      noneAtGoal = false;
        }
	  }
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
  int move = location;           // new location moved to if a ladder or chute
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
