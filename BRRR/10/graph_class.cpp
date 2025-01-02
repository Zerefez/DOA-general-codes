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

vector<GridLocation> Graph::grid_reconstruct_path(
	GridLocation start, GridLocation goal,
	unordered_map<GridLocation, GridLocation> came_from) {
	vector<GridLocation> path;
	GridLocation current = goal;
	if (came_from.find(goal) == came_from.end()) {
		return path; // no path can be found
	}
	while (current != start) {
		path.push_back(current);
		current = came_from[current];
	}
	path.push_back(start); // optional
	reverse(path.begin(), path.end());
	return path;
}

void Graph::a_star(GridLocation start, GridLocation goal,
	unordered_map<GridLocation, GridLocation>& came_from,
	unordered_map<GridLocation, double>& cost_so_far) {
	struct pos_comp {
		constexpr bool operator()(pair<int, GridLocation> const& a, pair<int, GridLocation> const& b) const noexcept {
			return a.first > b.first;
		}
	};
	priority_queue < pair<int, GridLocation>, vector<pair<int, GridLocation>>, pos_comp> frontier;
	frontier.push(make_pair(0, start));

	came_from[start] = start;
	cost_so_far[start] = 0;

	while (!frontier.empty()) {
		GridLocation current = frontier.top().second;
		frontier.pop();

		if (current == goal) {
			break;
		}

		for (GridLocation next : grid_neighbors(current)) {
			double new_cost = cost_so_far[current] + 1; // fixed edge cost 1
			if (cost_so_far.find(next) == cost_so_far.end()
				|| new_cost < cost_so_far[next]) {
				cost_so_far[next] = new_cost;
				double priority = new_cost + heuristic(next, goal);
				frontier.push(make_pair(priority, next));
				came_from[next] = current;
			}
		}
	}
}

