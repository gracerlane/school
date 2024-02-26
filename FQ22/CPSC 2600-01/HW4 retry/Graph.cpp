// Grace Lane
// 19 November 2022
// Graph.cpp

#include <iostream>
#include <fstream>
#include <queue>
#include "Graph.h"

using namespace std;

// constructor that creates an empty graph
Graph::Graph()
{
	vertices = 0;
	adjMat = nullptr;
}

// loads the file given from the command line and creates the graph accordingly
void Graph::load(char *filename)
{
	ifstream input;
	string inputFile = filename;

	input.open(inputFile);                 // open the given file

	if (input.fail()) {                    // if the file fails to open, the program will stop
		cout << endl;
		cout << "file error... exiting program... press enter...";
		cin.get();
		cout << endl;
		return;
  }

	cout << inputFile << ":" << endl << endl;

	input >> vertices;                                 // takes the first int from the file and sets vertices to the value
	
	adjMat = new int* [vertices];                      // dynamically allocate array of size vertices

	for (int i = 0; i < vertices; i++) {
		adjMat[i] = new int[vertices];
	}

	for (int j = 0; j < vertices; j++) {        // sets all values to 0
		for (int k = 0; k < vertices; k++) {
			adjMat[j][k] = 0;
		}
	}

	int start, end;
	while (input.peek() != EOF) {               // while there is still info in the file,  
		input >> start;                           // make the first int start and the next one end
		input >> end;
		adjMat[start][end] = 1;                   // and put a 1 in their positions in the adjacency matrix
		adjMat[end][start] = 1;
	}
}

// displays the adjacency matrix of the desired graph from the file
void Graph::display()      
{
	cout << "Adjacency Matrix" << endl;
	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			cout << adjMat[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

// recursive depth-first search function to complete the search and display results
void Graph::displayDFS(int vertex)
{
	if (!seen) {
		for (int i = 0; i < vertices; i++) {        // sets all values to false in boolean array
			seen[i] = false;
		}
	}

	if (!seen[vertex]) {
		seen[vertex] = true;
		cout << vertex << " ";
		for (int i = 0; i < vertices; i++) {
			if (adjMat[vertex][i]) {          // if there is a 1 in adjMat then call the function again
				displayDFS(i);
			}
		}
	}
}

// breadth-first search
void Graph::displayBFS(int vertex)
{
	for (int i = 0; i < vertices; i++) {            // sets all index values to false in the bool array
		seen[i] = false;
	}

	queue <int> queueBFS;                           // creates a queue for the BFS
	seen[vertex] = true;
	queueBFS.push(vertex);

	while (queueBFS.empty() == false) {             // while the queue is not empty, push values in and pop them out accordingly
		int vert = queueBFS.front();                  
		queueBFS.pop();                               
		cout << vert << " ";                          
		for (int i = 0; i < vertices; i++) {           
			if (adjMat[vert][i] && !seen[i]) {
				seen[i] = true;
				queueBFS.push(i);
			}
		}
	}

	cout << endl;
}

Graph::~Graph()
{
  for(int i = 0; i < vertices; i++){
    delete [] adjMat[i];
  }

  delete [] adjMat;
  delete [] seen;
}
