// Grace Lane
// 19 November 2022
// Purpose: This program will:
//  1. Create an empty graph.
//  2. Loads the graph using the specified input file.
//  3. Display the adjacency matrix.
//  4. Display a depth first search starting at vertex 0.
//  5. Display a breadth first search starting at vertex 0.

#include <iostream>
#include <fstream>
#include <queue>
#include "Graph.h"

using namespace std;

int main(int argc, char* argv[])
{
	cout << endl;
	cout << "Welcome to HW4: Program! The following is the adjacency matrix," << endl;
	cout << "the DFS results and the BFS results of the given graph." << endl;
	cout << endl;

	Graph graph;

	graph.load(argv[1]);
	graph.display();
	cout << "DFS at vertex 0: ";
	graph.displayDFS(0);
	cout << endl;
	cout << "BFS at vertex 0: ";
	graph.displayBFS(0);
	
	return 0;
}

