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
	digraph.addWeightedEdge(2, 4, -30);
	digraph.addWeightedEdge(3, 5, 20);
	digraph.addWeightedEdge(4, 3, 45);
	digraph.addWeightedEdge(4, 5, 25);
	digraph.print();

	//Sort
	cout << "Topological sort: ";
	digraph.topologicalSort(0);
	cout << endl;

	//Test newly implemented algorithm.
	//Should result in 0->2->4->5 due to negative distance between 2 and 5.
	int goalVertex{ 5 };
	std::cout << "\nShortest path from 0 to " << goalVertex << " using Bellman-Ford:\n";
	vector<int> startToGoalPath{ digraph.bellman_ford(0,goalVertex,path,dist) };
	for (auto vertex : startToGoalPath)
	{
		if (vertex != goalVertex)
			std::cout << vertex << " -> ";
		else
			std::cout << vertex << "\n";
	}


	//With negative cycles (Move comments to code above to test)

	/*
	//Create variables
	Graph digraph(3);
	vector<int> path(3), dist(3);

	//Set weigths
	digraph.addWeightedEdge(0, 1, -1);
	digraph.addWeightedEdge(1, 2, -1);
	digraph.addWeightedEdge(2, 0, -1);
	digraph.print();

	//Sort
	cout << "Topological sort: ";
	digraph.topologicalSort(0);
	cout << endl;

	//Test newly implemented algorithm.
	//Should result in 0->2->4->5 due to negative distance between 2 and 5.
	int goalVertex{ 2 };
	std::cout << "\nShortest path from 0 to " << goalVertex << " using Bellman-Ford:\n";
	vector<int> startToGoalPath{ digraph.bellman_ford(0,goalVertex,path,dist) };
	for (auto vertex : startToGoalPath)
	{
		if (vertex != goalVertex)
			std::cout << vertex << " -> ";
		else
			std::cout << vertex << "\n";
	}
	*/
}