using namespace std;
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <climits>
#include <algorithm>
#include "matrix_class.h"
#include "disjoint_sets.h"

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

	void addEdge(int u, int v);
	void addDirectedEdge(int u, int v);
	void addWeightedEdge(int u, int v, int w);
	void dfs(int v, vector<int>& path);
	void bfs(int s, vector<int>& path, vector<int>& dist);
	void topologicalSort(int v);
	/**
	 * Count the number of connected components in the graph.
	 */
	int connectedComponents();

	/*
	 * Compute the single-source shortest path from node s to every other node
	 * in the graph. Path will store the edges of the shortest paths and dist
	 * the actual distances.
	 */
	void dijkstra(int s, vector<int>& path, vector<int>& dist);
	void dijkstra_nopq(int s, vector<int>& path, vector<int>& dist);
	vector<int> bellman_ford(int s, int goalVertex, vector<int>& path, vector<int>& dist); //Assignment function
	/**
	 * Compute all-shortest paths.
	 * dist contains the values of the shortest path.
	 * Vertices are numbered starting at 0; all arrays
	 * have equal dimension. A negative cycle exists if
	 * dist[i][i] is set to a negative value.
	 * Actual path can be computed using path[][].
	 */
	void allPairs(Matrix<int>& path, Matrix<int>& dist);

	int kruskalMST();
	int primMST();
	void print();
};
