#include "graph_class.h"

void test(string tstname, bool tst) {
	cout << tstname + ": " + string(tst == true ? "PASS" : "FAIL") << endl;
}

// Driver code
int main() {

	Graph graph(5);
	vector<int> upath(5), udist(5);

	graph.addEdge(0, 1);
	graph.addEdge(0, 4);
	graph.addEdge(1, 2);
	graph.addEdge(1, 3);
	graph.addEdge(1, 4);
	graph.addEdge(2, 3);
	graph.addEdge(3, 4);
	graph.print();
	graph.print_graph_graphviz();

	graph.dfs(0, upath);
	graph.bfs(0, upath, udist);

	for (int i = 0; i < 5; i++) {
		cout << "Distance from 0 to " << i << " is " << udist[i] << endl;
	}
	cout << graph.connectedComponents() << " connected component(s)" << endl;

	Graph digraph(8);
	vector<int> path(8), dist(8);
	cout << " === Graph: weighted no negative === " << endl;
	digraph.addWeightedEdge(0, 1, 3);
	digraph.addWeightedEdge(0, 2, 1);
	digraph.addWeightedEdge(1, 2, 2);
	digraph.addWeightedEdge(1, 3, 4);
	digraph.addWeightedEdge(1, 4, 11);
	digraph.addWeightedEdge(3, 4, 6);
	digraph.addWeightedEdge(3, 6, 2);
	digraph.addWeightedEdge(4, 7, 0);
	digraph.addWeightedEdge(5, 4, 1);
	digraph.addWeightedEdge(7, 4, 4);
	//digraph.printw();
	digraph.print_digraph_graphviz();

	Graph digraph_neg(4);
	vector<int> path_neg(3), dist_neg(4);
	cout << " === Graph: negative edges (no negative cycle) === " << endl;
	digraph_neg.addWeightedEdge(0, 1, 3);
	digraph_neg.addWeightedEdge(1, 2, 14);
	digraph_neg.addWeightedEdge(1, 3, 12);
	digraph_neg.addWeightedEdge(2, 3, -6);
	//digraph_neg.printw();
	digraph_neg.print_digraph_graphviz();

	cout << " --- Dijkstra --- " << endl;
	digraph.dijkstra(0, path, dist);
	for (int i = 0; i < 8; i++) {
		cout << "Distance from 0 to " << i << " is " << dist[i] << endl;
	}
	for (int i = 0; i < 8; i++) {
		cout << "Path " << i << " is " << path[i] << endl;
	}

	test("Test Dijkstra correct path", path == (vector<int>{-1, 0, 0, 1, 3, -1, 3, 4}));
	test("Test Dijkstra correct dist", dist == (vector<int>{0, 3, 1, 7, 13, INF, 9, 13}));

	cout << " --- Dijhkstra with early exit --- " << endl;
	vector<int> route = digraph.dijkstra(0, 6, path, dist);
	cout << "Route 0->6: ";
	for (auto node : route)
		cout << node << ", ";
	cout << endl;

	test("Test no valid path (0-5)", digraph.dijkstra(0, 5, path, dist) == (vector<int>{}));
	test("Test valid path (1-6)", digraph.dijkstra(1, 6, path, dist) == (std::vector<int>{1, 3, 6}));
	test("Test valid path longer but less expensive (0-4)", digraph.dijkstra(0, 4, path, dist) == (std::vector<int>{0, 1, 3, 4}));
	test("Test valid path with loop (0-7)", digraph.dijkstra(0, 7, path, dist) == (std::vector<int>{0, 1, 3, 4, 7}));

	cout << " --- Dijkstra negative --- " << endl;
	digraph_neg.dijkstra(0, path_neg, dist_neg);
	for (int i = 0; i < 4; i++) {
		cout << "Distance from 0 to " << i << " is " << dist_neg[i] << endl;
	}

	cout << " --- Bellman-Ford --- " << endl;
	bool res = digraph_neg.bellman_ford(0, path_neg, dist_neg);
	if (res) {
		for (int i = 0; i < 4; i++) {
			cout << "Distance from 0 to " << i << " is " << dist_neg[i] << endl;
		}
	}
	else {
		cout << "negative cycle detected!!!" << endl;
	}
	cout << endl;

	cout << " === Graph: negative cycle  === " << endl;
	Graph digraph_neg_cycle(4);
	vector<int> path_neg_cycle(4), dist_neg_cycle(4);
	// negative cycle
	digraph_neg_cycle.addWeightedEdge(0, 1, 1);
	digraph_neg_cycle.addWeightedEdge(1, 2, 3);
	digraph_neg_cycle.addWeightedEdge(1, 3, -10);
	digraph_neg_cycle.addWeightedEdge(3, 0, 5);
	digraph_neg_cycle.printw();
	
	cout << " --- Dijkstra --- " << endl;
	digraph_neg_cycle.dijkstra(0, path_neg_cycle, dist_neg_cycle);
	for (int i = 0; i < 5; i++) {
		cout << "Distance from 0 to " << i << " is " << dist_neg_cycle[i] << endl;
	}

	cout << " --- Bellman-Ford --- " << endl;
	res = digraph_neg_cycle.bellman_ford(0, path_neg_cycle, dist_neg_cycle);
	if (res) {
		for (int i = 0; i < 5; i++) {
			cout << "Distance from 0 to " << i << " is " << dist_neg_cycle[i] << endl;
		}
	}
	else {
		cout << "negative cycle detected!!!" << endl;
	}
	cout << endl;

	cout << " === Graph: DAG  === " << endl;
	Graph dag(5);
	vector<int> dag_path(4), dag_dist(5);
	dag.addWeightedEdge(0, 1, 2);
	dag.addWeightedEdge(0, 2, 6);
	dag.addWeightedEdge(1, 2, 7);
	dag.addWeightedEdge(1, 3, 4);
	dag.addWeightedEdge(1, 4, 2);
	dag.addWeightedEdge(2, 3, -1);
	dag.addWeightedEdge(2, 4, 1);
	dag.addWeightedEdge(3, 4, -2);
	//dag.printw();
	dag.print_digraph_graphviz();

	cout << " --- DAG-shortest-path --- " << endl;
	dag.dag_shortest_path(0, dag_path, dag_dist);
	for (int i = 0; i < 5; i++) {
		cout << "Distance from 0 to " << i << " is " << dag_dist[i] << endl;
	}

	return 0;
}
