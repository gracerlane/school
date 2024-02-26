// Grace Lane
// 16 May 2022
// assignment3.cpp

#include <iostream>
#include <string>
#include <iomanip>
#include "BST.h"

using namespace std;

const int QUIT = 0;

const string MENU = "m";

int main() 
{
	int answer;
	int nodeIn;
	int found = 1;
	int pre;
	int suc;
	int del; 
	BST t;
	
	while (answer =! QUIT) {
		cout << endl;
		cout << "Please select an operation to test:" << endl;
		cout << "1. Insert a node" << endl
				 << "2. Search for a value" << endl
				 << "3. Find predecessor for an existing value" << endl
				 << "4. Find successor for an existing value" << endl
			 	 << "5. Find height of tree" << endl
				 << "6. Find total number of nodes in tree" << endl
				 << "7. Delete a node" << endl
				 << "8. Traverse inorder and display" << endl
				 << "9. Traverse preorder and display" << endl
				 << "10. Traverse postorder and display" << endl
				 << "11. Check if tree is balanced" << endl
				 << "12. Destroy tree" << endl
				 << "0. Quit" << endl;
		cout << endl;
		t.inorderDisplay();
		cout << endl;
		cout << "Menu Choice: ";
		cin >> answer;
		cin.ignore();

		switch (answer) {
			case 1:
				cout << "Node to insert: ";
				cin >> nodeIn;
				cin.ignore();
				found = t.searchNode(nodeIn);
				while (found == 1) {
					cout << "Already inserted, enter another value: ";
					cin >> nodeIn;
					cin.ignore();
					found = t.searchNode(nodeIn);
				}
				t.insertNode(nodeIn);
				break;

			case 2:
				cout << "Node to search: ";
				cin >> nodeIn;
				cin.ignore();
				found = t.searchNode(nodeIn);
				if (found == 1) {
					cout << "Found" << endl;
				} else {
					cout << "Not Found" << endl;
				}
				cout << "Press enter to return to menu...";
				cin.get();
				break;

			case 3:
				cout << "Node to find predecessor of: ";
				cin >> nodeIn;
				cin.ignore();
				// found = t.searchNode(nodeIn);
				// while (found == -1) {
				// 	cout << "Value is not in the tree, enter another value: ";
				// 	cin >> nodeIn;
				// 	cin.ignore();
				// 	found = t.searchNode(nodeIn);
				// }
				
				if (t.predNode(nodeIn) == nodeIn) {
					cout << "No predecessor" << endl;
				} else {
					cout << "Predecessor: " << t.predNode(nodeIn) << endl;
				}
				
				cout << "Press enter to return to menu...";
				cin.get();
				break;

			case 4:
				cout << "Node to find successor of: ";
				cin >> nodeIn;
				cin.ignore();
				// found = t.searchNode(nodeIn);
				// while (found == -1) {
				// 	cout << "Value is not in the tree, enter another value: ";
				// 	cin >> nodeIn;
				// 	cin.ignore();
				// 	found = t.searchNode(nodeIn);
				// }
				
				if (t.successNode(nodeIn) == nodeIn) {
					cout << "No successor" << endl;
				} else {
					cout << "Successor: " << t.successNode(nodeIn) << endl;
				}
				
				cout << "Press enter to return to menu...";
				cin.get();
				break;

			case 5:
				cout << "Height of the tree: ";
				if (t.heightTree() == 0) {
					cout << "Empty Tree";
				} else {
					cout << t.heightTree() << endl;
				}
				cout << "Press enter to return to menu...";
				cin.get();
				break;

			case 6:
				cout << "Total number of nodes: ";
				if (t.totalNodes() == 0) {
					cout << "Empty Tree";
				} else {
					cout << t.totalNodes() << endl;
				}				cout << "Press enter to return to menu...";
				cin.get();
				break;

			case 7:
				cout << "Enter a leaf node to delete: ";
				cin >> del;
				cin.ignore();
				t.deleteANode(del);
				cout << "Press enter to return to menu...";
				cin.get();
				break;

			case 8:
				cout << "Inorder display: ";
				t.inorderDisplay();
				cout << endl;
				cout << "Press enter to return to menu...";
				cin.get();
				break;

			case 9:
				cout << "Preorder display: ";
				t.preorderDisplay();
				cout << endl;
				cout << "Press enter to return to menu...";
				cin.get();
				break;

			case 10:
				cout << "Postorder display: ";
				t.postorderDisplay();
				cout << endl;
				cout << "Press enter to return to menu...";
				cin.get();
				break;

			default:
				return 0;
		}
	}
}
