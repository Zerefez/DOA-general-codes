#include <iostream>
#include "graph_class.h"

int main()
{

	//Create variables
	Graph digraph(6);
	vector<int> path(6), dist(6);

	//Set weigths
	digraph.addWeightedEdge(0, 1, 5);
	digraph.addWeightedEdge(0, 2, 35);
	digraph.addWeightedEdge(0, 3, 40);
	digraph.addWeightedEdge(1, 3, 20);
	digraph.addWeightedEdge(1, 4, 25);
	digraph.addWeightedEdge(2, 5, 30);
	digraph.addWeightedEdge(2, 4, 30); //Changed to 30 from -30
	digraph.addWeightedEdge(3, 5, 20);
	digraph.addWeightedEdge(4, 3, 45);
	digraph.addWeightedEdge(4, 5, 25);
	digraph.print();

	//Test topological dijkstra algorithm
	int goalVertex{ 5 };
	std::cout << "\nShortest path from 0 to " << goalVertex << " using topological dijkstra:\n";
	vector<int> startToGoalPath{ digraph.dijkstra(0,goalVertex,path,dist) };

	for (auto vertex : startToGoalPath)
	{
		if (vertex != goalVertex)
			std::cout << vertex << " -> ";
		else
			std::cout << vertex << "\n";
	}

}