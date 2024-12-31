
#pragma once
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <array>

using namespace std;

#define INFINITY 1000000

struct GridLocation {
	int x, y;
};

inline bool operator == (GridLocation a, GridLocation b) {
	return a.x == b.x && a.y == b.y;
}

inline bool operator != (GridLocation a, GridLocation b) {
	return !(a == b);
}

inline bool operator < (GridLocation a, GridLocation b) {
	// lexicographical comparison
	return tie(a.x, a.y) < tie(b.x, b.y);
}

inline basic_iostream<char>::basic_ostream& operator<<(basic_iostream<char>::basic_ostream& out, const GridLocation& loc) {
	out << '(' << loc.x << ',' << loc.y << ')';
	return out;
}

// 4-way Manhattan
inline double heuristic(GridLocation a, GridLocation b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

namespace std {
	/* implement hash function so we can put GridLocation into an unordered_set */
	template <> struct hash<GridLocation> {
		size_t operator()(const GridLocation& id) const noexcept {
			return hash<int>()(id.x ^ (id.y << 16));
		}
	};
}



class Graph {
private:

	// Square grid graph types and methods
	int width, height;

	array<GridLocation, 4> grid_dirs = {
		/* East, West, North, South */
		GridLocation{1, 0}, GridLocation{-1, 0},
		GridLocation{0, -1}, GridLocation{0, 1}
	};

	unordered_set<GridLocation> grid_walls;

	bool grid_in_bounds(GridLocation id) const {
		return 0 <= id.x && id.x < width
			&& 0 <= id.y && id.y < height;
	}

	bool grid_passable(GridLocation id) const {
		return grid_walls.find(id) == grid_walls.end();
	}

	vector<GridLocation> grid_neighbors(GridLocation id) const {
		vector<GridLocation> results;

		for (GridLocation dir : grid_dirs) {
			GridLocation next{ id.x + dir.x, id.y + dir.y };
			if (grid_in_bounds(next) && grid_passable(next)) {
				results.push_back(next);
			}
		}

		return results;
	}

public:
	/**
  * Methods for use in A* search in graph represented as 4-way grid.
  */

  /**
   * Constructor for 4-way grids of width x heigth. All locations are
   * implicitly connected in the grid, so the constructor only needs to
   * store widt and heigth. Only by adding walls (grid_add_wall) are
   * conections 'broken'
   */
	Graph(int width, int height) :
		width(width), height(height) {
	}

	/**
  * Add a rectangular wall from (x1,y1) to (x2,y2) to graph grid.
  */
	void grid_add_wall(int x1, int y1, int x2, int y2);

	/**
  * Reconstructs the path from goal to start and returns it reversed.
  * Input parameter came_from maps for each location to its predecessor in the
  * A* search. (GridLocation is a simple typedef for a (x,y) position).
  */
	vector<GridLocation> grid_reconstruct_path(GridLocation start, GridLocation goal,
		unordered_map<GridLocation, GridLocation> came_from);
	/**
  * Draw the grid graph and A* search result. Options to print
  * came_from, the path, and the distances (costs) of locations as
  * discovered in the search
  */
	void grid_draw(unordered_map<GridLocation, double>* distances = nullptr,
		unordered_map<GridLocation, GridLocation>* point_to = nullptr,
		vector<GridLocation>* path = nullptr,
		GridLocation* start = nullptr,
		GridLocation* goal = nullptr);
	/**
  * The A* search
  */
	void a_star(GridLocation start, GridLocation goal,
		unordered_map<GridLocation, GridLocation>& came_from,
		unordered_map<GridLocation, double>& cost_so_far);
};
