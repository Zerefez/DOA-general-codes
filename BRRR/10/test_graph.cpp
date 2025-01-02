#include "graph_class.h"

// Driver code
int main() {

	Graph graph(10, 10);
	graph.grid_add_wall(2, 2, 2, 2);
	graph.grid_add_wall(2, 3, 5, 3);
	graph.grid_add_wall(5, 4, 5, 4);
	graph.grid_add_wall(3, 5, 3, 5);
	graph.grid_add_wall(5, 6, 5, 7);
	GridLocation start{ 1, 5 }, goal{ 6, 3 };
	unordered_map<GridLocation, GridLocation> came_from;
	unordered_map<GridLocation, double> cost_so_far;
	graph.a_star(start, goal, came_from, cost_so_far);
	graph.grid_draw(nullptr, &came_from, nullptr, &start, &goal);
	cout << '\n';
	vector<GridLocation> apath = graph.grid_reconstruct_path(start, goal, came_from);
	graph.grid_draw(nullptr, nullptr, &apath, &start, &goal);
	cout << '\n';
	graph.grid_draw(&cost_so_far, nullptr, nullptr, &start, &goal);

	return 0;
}
