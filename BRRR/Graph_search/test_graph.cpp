#include "graph_class.h"

// Driver code
int main() {

	Graph graph(5);
	vector<int> path(5), dist(5);

	graph.addEdge(0, 1);
	graph.addEdge(0, 4);
	graph.addEdge(1, 2);
	graph.addEdge(1, 3);
	graph.addEdge(1, 4);
	graph.addEdge(2, 3);
	graph.addEdge(3, 4);
	graph.print();
	graph.dfs(0, path);
	graph.bfs(0, path, dist);

	for (int i = 0; i < 5; i++) {
		cout << "Distance from 0 to " << i << " is " << dist[i] << endl;
	}
	cout << graph.connectedComponents() << " connected component(s)" << endl;

	Graph digraph(7);
	path.resize(7);
	dist.resize(7);
	digraph.addWeightedEdge(0, 1, 1);
	digraph.addWeightedEdge(0, 2, 5);
	digraph.addWeightedEdge(0, 3, 2);
	digraph.addWeightedEdge(1, 3, 4);
	digraph.addWeightedEdge(1, 4, 3);
	digraph.addWeightedEdge(2, 5, 1);
	digraph.addWeightedEdge(3, 2, 4);
	digraph.addWeightedEdge(3, 5, 2);
	digraph.addWeightedEdge(3, 6, 2);
	digraph.addWeightedEdge(4, 3, 1);
	digraph.addWeightedEdge(4, 6, 10);
	digraph.addWeightedEdge(6, 5, 8);
	digraph.print();
	cout << "Topological sort: ";
	digraph.topologicalSort(0);
	cout << endl;

	cout << " Dijhkstra " << endl;
	digraph.dijkstra(0, path, dist);
	for (int i = 0; i < 7; i++) {
		cout << "Distance from 0 to " << i << " is " << dist[i] << endl;
	}
	cout << digraph.connectedComponents() << " connected component(s)" << endl;

	Matrix<int> dists(7, 7);
	Matrix<int> paths(7, 7);
	digraph.allPairs(paths, dists);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (dists[i][j] < INFINITY) {
				cout << "Distance from " << i << " to " << j << " is " << dists[i][j] << endl;
			}
			else {
				cout << "There is no path from " << i << " to " << j << endl;
			}
		}
	}

	// Make the graph undirected
	digraph.addWeightedEdge(1, 0, 1);
	digraph.addWeightedEdge(2, 0, 5);
	digraph.addWeightedEdge(3, 0, 2);
	digraph.addWeightedEdge(3, 1, 4);
	digraph.addWeightedEdge(4, 1, 3);
	digraph.addWeightedEdge(5, 2, 1);
	digraph.addWeightedEdge(2, 3, 4);
	digraph.addWeightedEdge(5, 3, 2);
	digraph.addWeightedEdge(6, 3, 2);
	digraph.addWeightedEdge(3, 4, 1);
	digraph.addWeightedEdge(6, 4, 10);
	digraph.addWeightedEdge(5, 6, 8);
	digraph.print();

	cout << "Kruskal's Minimum Spannig Tree has the following edges: ";
	int weight = digraph.kruskalMST();
	cout << "with weight of " << weight << endl;

	// Consider the graph undirected
	cout << "Prims's Minimum Spannig Tree has the following edges: ";
	weight = digraph.primMST();
	cout << "with weight of " << weight << endl;

	return 0;
}
