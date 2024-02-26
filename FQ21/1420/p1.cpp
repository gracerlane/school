// Grace Lane
// p1.cpp
// 10/06/2021
// Purpose: The purpose of this program is to allow the user to
//  input words or numbers to complete a paragraph. The paragraph will be 
//  printed at the end of the program.

#include <iostream>
#include <string>

using namespace std;

int main()
{
  // these are for user input 
  string ownerName;
  string dogName1;
  string dogName2;
  string animal;
  string pastTenseAction;
  string presentTenseAction;
  string restaurant;
  string showName;
  double chasingHours = 0;
  double watchingHours = 0;
  
  cout << endl << endl;
  cout << "Welcome, user! This is a short word game where you will " << endl;
  cout << "be asked to input either a word or a number. In the " << endl;
  cout << "end, the program will print out the final paragraph " << endl;
  cout << "for you to read!" << endl;
  cout << endl << endl;
  
  cout << "Enter your name: ";
  getline(cin, ownerName);
  
  cout << "Enter a different name: ";
  getline(cin, dogName1);
  
  cout << "Enter another name: ";
  getline(cin, dogName2);
  
  cout << "Enter a type of animal: ";
  getline(cin, animal);
  
  cout << "Enter a past tense action: ";
  getline(cin, pastTenseAction);
  
  cout << "Enter a present tense action(verb ending in -ing): ";
  getline(cin, presentTenseAction);
  
  cout << "Enter a name of a restaurant: ";
  getline(cin, restaurant);

  cout << "Enter a name of a TV show: ";
  getline(cin, showName);
  
  cout << "Enter a number: ";
  cin >> chasingHours;
  cin.ignore();
  
  cout << "Enter another number: ";
  cin >> watchingHours;
  cin.ignore();
  
  cout << endl << endl;
  cout << "Press enter to see results...";
  cin.get();
  
  cout << endl << endl;
  cout << ownerName << " had two dogs named " << dogName1 << " and" << endl;
  cout << dogName2 << ". One day, " << ownerName << " decided to take" << endl;
  cout << "the dogs on a walk. While they were walking, a(n)" << endl;
  cout << animal << " " << pastTenseAction << " in front of them." << endl;
  cout << ownerName << " was so shocked that they let go of the" << endl;
  cout << "leashes and " << dogName1 << " and " << dogName2 << " ran" << endl;
  cout << "after the " << animal << ". The dogs chased the " << animal << endl;
  cout << "for " << chasingHours << " hour(s) until " << ownerName << endl;
  cout << "finally caught them. They headed to " << restaurant << endl;
  cout << "to eat and then went home. At home " << ownerName << endl;
  cout << "watched " << watchingHours << " hour(s) of " << showName << endl;
  cout << "before " << presentTenseAction << " and then going" << endl;
  cout << "to bed." << endl;
  
  cout << endl << endl;
  cout << "Thank you so much for playing my word game!" << endl;
  cout << endl << endl;
  
  return 0;
}