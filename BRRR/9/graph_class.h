
#pragma once

#include <vector>
#include <queue>
#include <stack>
#include <iostream>
#include <climits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
/* #include "matrix_class.h" */
using namespace std;

//#define INF 1000000
#define INF INT_MAX

class Graph {
private:
	vector<vector<int>> adj;
	vector<vector<int>> weight;

	// Square grid graph types and methods
	int width, height;

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
			weight[i].resize(vertices, INF);
			weight[i][i] = 0; // Initialize self-edges with zero cost.
		}
	}

	void addEdge(int u, int v);
	void addDirectedEdge(int u, int v);
	void addWeightedEdge(int u, int v, int w);
	void dfs(int v, vector<int>& path);
	void bfs(int s, vector<int>& path, vector<int>& dist);
	void topologicalSort(int v, stack<int>& sorting);
	/**
	 * Count the number of connected components in the graph.
	 */
	int connectedComponents();

	/**
	 * Compute the single-source shortest path from node s to every other node
	 * in the graph. Path will store the edges of the shortest paths and dist
	 * the actual distances.
	 */
	void dijkstra(int s, vector<int>& path, vector<int>& dist);

	vector<int> dijkstra(int s, int goal, vector<int>& path, vector<int>& dist);

	void dijkstra_pq(int s, vector<int>& path, vector<int>& dist);

	bool bellman_ford(int s, vector<int>& path, vector<int>& dist);

	void dag_shortest_path(int s, vector<int>& path, vector<int>& dist);

	void print();
	void printw();
	void print_digraph_graphviz();
	void print_graph_graphviz();
};
