/********* YOUR ARE NOT ALLOWED TO CHANGE ANYTHING IN THIS FILE***********/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

struct Node {
    int value;
    Node * next;
};

vector<int> readLineToVector(char * inputFileName, int targetLineNum){
    vector<int> numsVec;
    string line;
    int curLineNum = 1, num;

    ifstream inFile(inputFileName); //open the input file

    //read the next line untill it reaches the end.
    while (getline(inFile, line)) {
        //find target line and save the nums in targeted line into 
        //a vector for creating list later
        if (curLineNum++ == targetLineNum){
            stringstream stream(line); 
            while(stream >> num){
                numsVec.push_back(num);
            }
        }
    }
    inFile.close(); //close file when done

    return numsVec;
}

Node * createListFromFile(char * inputFileName, int targetLineNum){
    // read a target line into a vector of int
    vector<int> numsVec = readLineToVector(inputFileName, targetLineNum);

    Node * head = nullptr;
    Node * currNode = head;

    //create a new node for each number in the line
    //and chain all nodes together to get the list
    for (int num : numsVec){
        //create a new node
        Node * newNode = new Node();
        newNode->value = num;
        newNode->next = nullptr;

        //chain to existing list
        if (head){
            currNode->next = newNode;
            currNode = newNode;
        }else{
            head = newNode;
            currNode = newNode;
        }
    }

    return head;
}

//print a given list
void printList(Node * head){
    Node * currNode = head;
    cout << "head -> ";
    while (currNode){
        cout << currNode->value << " -> ";
        currNode = currNode->next;
    }
    cout << "null" << endl;
}
/********* YOUR ARE NOT ALLOWED TO CHANGE ANYTHING IN THIS FILE***********/
