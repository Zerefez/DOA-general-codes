#include <iostream>
#include "graph_class.h"

int main()
{
	//Create variables
	Graph digraph(7);
	vector<int> path(7), dist(7);

	//Set weigths
	digraph.addWeightedEdge(0, 1, 1);
	digraph.addWeightedEdge(0, 2, 5);
	digraph.addWeightedEdge(0, 3, 2);
	digraph.addWeightedEdge(1, 3, 4);
	digraph.addWeightedEdge(1, 4, 3);
	digraph.addWeightedEdge(2, 5, 1);
	digraph.addWeightedEdge(3, 2, 4);
	digraph.addWeightedEdge(3, 5, 2);
	digraph.addWeightedEdge(3, 6, 2);
	digraph.addWeightedEdge(4, 3, 1);
	digraph.addWeightedEdge(4, 6, 10);
	digraph.addWeightedEdge(6, 5, 8);
	digraph.print();

	//Sort
	cout << "Topological sort: ";
	digraph.topologicalSort(0);
	cout << endl;

	//Dijkstra's algorithm
	cout << " Dijkstra " << endl;
	digraph.dijkstra(0, path, dist);
	for (int i = 0; i < 7; i++) {
		cout << "Distance from 0 to " << i << " is " << dist[i] << endl;
	}
	cout << digraph.connectedComponents() << " connected component(s)" << endl;


	//Test newly implemented algorithm
	int goalVertex{ 6 };
	std::cout << "** Test Assignment 1 - dijkstra with early exit **\n";
	std::cout << "Shortest path from 0 to " << goalVertex << ":\n";
	vector<int> startToGoalPath{ digraph.dijkstraShortestPathOnly(0,goalVertex,path,dist) };
	for (auto vertex : startToGoalPath)
	{
		if (vertex != goalVertex)
			std::cout << vertex << " -> ";
		else
			std::cout << vertex << "\n";
	}


	// Ex5
	// Creates the graph
	// Define the 10x10 grid
	//std::vector<std::vector<int>> grid = {
	//	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	//	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	//	{1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
	//	{1, 1, 0, 0, 0, 0, 1, 1, 1, 1},
	//	{1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
	//	{1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
	//	{1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
	//	{1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
	//	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	//	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	//};


	//// Print the grid to see if we are on right track
	//for (const auto& row : grid) {
	//	for (int cell : row) {
	//		std::cout << cell << " ";
	//	}
	//	std::cout << std::endl;
	//}


}