#include "graph_class.h"
#include <queue>
#include <climits>
#include <iomanip>

using namespace std;

void Graph::grid_add_wall(int x1, int y1, int x2, int y2) {
	for (int x = x1; x <= x2; ++x) {
		for (int y = y1; y <= y2; ++y) {
			grid_walls.insert(GridLocation{ x, y });
		}
	}
}

void Graph::grid_draw(unordered_map<GridLocation, double>* distances,
	unordered_map<GridLocation, GridLocation>* point_to,
	vector<GridLocation>* path,
	GridLocation* start,
	GridLocation* goal) {
	const int field_width = 3;
	cout << string(field_width * width, '_') << '\n';
	for (int y = 0; y != height; ++y) {
		for (int x = 0; x != width; ++x) {
			GridLocation id{ x, y };
			if (grid_walls.find(id) != grid_walls.end()) {
				cout << string(field_width, '#');
			}
			else if (start && id == *start) {
				cout << " S ";
			}
			else if (goal && id == *goal) {
				cout << " T ";
			}
			else if (path != nullptr && find(path->begin(), path->end(), id) != path->end()) {
				cout << " @ ";
			}
			else if (point_to != nullptr && point_to->count(id)) {
				GridLocation next = (*point_to)[id];
				if (next.x == x + 1) { cout << " > "; }
				else if (next.x == x - 1) { cout << " < "; }
				else if (next.y == y + 1) { cout << " v "; }
				else if (next.y == y - 1) { cout << " ^ "; }
				else { cout << " * "; }
			}
			else if (distances != nullptr && distances->count(id)) {
				cout << ' ' << left << setw(field_width - 1) << (*distances)[id];
			}
			else {
				cout << " . ";
			}
		}
		cout << '\n';
	}
	cout << string(field_width * width, '~') << '\n';
}

// Functions to implement exercise 5
vector<GridLocation> Graph::grid_reconstruct_path(
	GridLocation start, GridLocation goal,
	unordered_map<GridLocation, GridLocation> came_from) {

	vector<GridLocation> path;

	// TO BE IMPLEMENETED

	GridLocation current = goal;

	// Trace back from goal to start
	while (current != start) {
		path.push_back(current);
		current = came_from[current];
	}

	// Reverse the path so it goes from start to goal
	reverse(path.begin(), path.end());
	return path;
}

void Graph::a_star(GridLocation start, GridLocation goal,
	unordered_map<GridLocation, GridLocation>& came_from,
	unordered_map<GridLocation, double>& cost_so_far) {

	// TO BE IMPLEMENETED

	// Priority queue to store GridLocations
	priority_queue<GridLocation> frontier;

	// Set initial cost and start point
	cost_so_far[start] = 0;
	came_from[start] = start;  // Starting point  
	frontier.push(start);  // Push the start location

	// While there are nodes to explore
	while (!frontier.empty()) {
		// Get the node (GridLocation) at the top
		GridLocation current = frontier.top();
		frontier.pop();

		// If we reach the goal, stop the search
		if (current == goal) {
			break;
		}

		// Explore neighbors of the current node
		for (GridLocation next : grid_neighbors(current)) {
			// Calculate the new cost to reach this neighbor
			// We know that the weight is 1 so we just add 1
			double new_cost = cost_so_far[current] + 1;

			// If this path is better, update the cost and add to the open set
			if (cost_so_far.find(next) == cost_so_far.end() || new_cost < cost_so_far[next]) {
				cost_so_far[next] = new_cost;
				came_from[next] = current;
				// Add the next location to the frontier
				frontier.push(next);
			}
		}
	}
}


