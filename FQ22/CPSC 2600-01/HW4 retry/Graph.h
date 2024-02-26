// Grace Lane
// 19 November 2022
// Graph.h

#include <iostream>

using namespace std;

#ifndef GRAPH_H
#define GRAPH_H
class Graph {
	private:
		int vertices;
		int** adjMat;
		bool* seen;
		void depthFirst(int vert, bool array[]);      // a recursive function for implementing DFS

	public:
		Graph();                                      // constructor
		void load(char *filename);                    // loads the given file
		void display();                               // displays the adjacency matrix
		void displayDFS(int vertex);                  // displays the DFS results
		void displayBFS(int vertex);                  // completes BFS and displays the results
		~Graph();
};
#endif
