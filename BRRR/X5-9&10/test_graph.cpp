#include "graph_class.h"

// Driver code
int main() {

	// Creates the graph from Ex5
	Graph graph(10, 10);
	graph.grid_add_wall(2, 2, 2, 2);
	graph.grid_add_wall(2, 3, 5, 3);
	graph.grid_add_wall(5, 4, 5, 4);
	graph.grid_add_wall(3, 5, 3, 5);
	graph.grid_add_wall(5, 6, 5, 7);

	// Set "S" and "T" positions in the grid
	GridLocation start{ 1, 5 }, goal{ 6, 3 };

	// Initialize maps to track "track" and "cost
	unordered_map<GridLocation, GridLocation> came_from;
	unordered_map<GridLocation, double> cost_so_far;

	// Use of the a_star implementation
	graph.a_star(start, goal, came_from, cost_so_far);

	// Draws the path
	graph.grid_draw(nullptr, &came_from, nullptr, &start, &goal);
	cout << '\n';
	graph.grid_draw(&cost_so_far, nullptr, nullptr, &start, &goal);

	vector<GridLocation> apath = graph.grid_reconstruct_path(start, goal, came_from);
	graph.grid_draw(nullptr, nullptr, &apath, &start, &goal);
	cout << '\n';

	return 0;
}
