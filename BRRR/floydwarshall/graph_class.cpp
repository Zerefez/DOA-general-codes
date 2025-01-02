using namespace std;
#include "graph_class.h"
#include <queue>
#include <climits>

void Graph::addEdge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::addDirectedEdge(int u, int v) {
	adj[u].push_back(v);
}

int Graph::connectedComponents() {
	int components = 0;
	stack < int >sorting;
	vector < int >path(adj.size());
	vector < bool >visited(adj.size());
	for (int v = 0; v < adj.size(); ++v) {
		visited[v] = false;
	}

	for (int v = 0; v < adj.size(); ++v) {
		if (!visited[v]) {
			++components;
			dfs(v, visited, path, sorting);
		}
	}

	return components;
}


void Graph::addWeightedEdge(int u, int v, int w) {
	adj[u].push_back(v);
	weight[u][v] = w;
}

void Graph::allPairs(Matrix < int >& path, Matrix < int >& dist) {
	int n = adj.size();
	// Initialize d and path
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dist[i][j] = weight[i][j];
			path[i][j] = -1;
		}
	}

	for (int k = 0; k < n; ++k) {
		// Consider each vertex as an intermediate
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (dist[i][k] + dist[k][j] < dist[i][j]) {
					// Update shortest path
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = k;
				}
			}
		}
	}
}


void Graph::print() {
	for (int v = 0; v < adj.size(); ++v) {
		cout << "Adjacency list of vertex " << v;
		for (auto x : adj[v])
			cout << " -> " << x;
		cout << endl;
	}
}
