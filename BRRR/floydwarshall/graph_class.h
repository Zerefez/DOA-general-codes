using namespace std;
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <climits>
#include <algorithm>
#include "matrix_class.h"
//#include "disjoint_sets.h"

#define INFINITY 1000000

class Graph {
private:
	vector<vector<int>> adj;
	vector<vector<int>> weight;

	void dfs(int v, vector<bool>& visited, vector<int>& path, stack<int>& sorting) {
		visited[v] = true;
		for (auto w : adj[v]) {
			if (!visited[w]) {
				path[w] = v;
				dfs(w, visited, path, sorting);
			}
		}
		sorting.push(v);
	}

public:
	Graph(int vertices = 1) : adj(vertices), weight(vertices) {
		for (int i = 0; i < vertices; i++) {
			weight[i].resize(vertices, INFINITY);
			weight[i][i] = 0; // Initialize self-edges with zero cost.
		}
	}

	// NEW!!! Constructor that takes a matrix of weights
	Graph(vector<vector<int>> its_weights) {
		int n = its_weights.size();  // Number of nodes
		weight = its_weights;       // Copy weights to the class variable
		adj.resize(n);              // Resize adjacency list to match the number of nodes
	}

	void addEdge(int u, int v);
	void addDirectedEdge(int u, int v);
	void addWeightedEdge(int u, int v, int w);

	/**
	 * Count the number of connected components in the graph.
	 */
	int connectedComponents();

	/**
	 * Compute all-shortest paths.
	 * dist contains the values of the shortest path.
	 * Vertices are numbered starting at 0; all arrays
	 * have equal dimension. A negative cycle exists if
	 * dist[i][i] is set to a negative value.
	 * Actual path can be computed using path[][].
	 */
	void allPairs(Matrix<int>& path, Matrix<int>& dist);

	void print();
};
