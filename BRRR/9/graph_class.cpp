#include "graph_class.h"
#include <queue>
#include <climits>
using namespace std;


void Graph::addEdge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::addDirectedEdge(int u, int v) {
	adj[u].push_back(v);
}

void Graph::dfs(int vertex, vector < int >& path) {
	stack < int >sorting;
	vector < bool >visited(adj.size());

	for (int v = 0; v < adj.size(); ++v) {
		visited[v] = false;
	}
	dfs(vertex, visited, path, sorting);
}

void Graph::bfs(int s, vector < int >& path, vector < int >& dist) {
	queue < int >q;
	vector < bool >visited(adj.size());

	for (int v = 0; v < adj.size(); ++v) {
		dist[v] = INT_MAX;
		visited[v] = false;
	}
	dist[s] = 0;
	visited[s] = true;
	q.push(s);

	while (!q.empty()) {
		s = q.front();
		q.pop();
		for (auto w : adj[s]) {
			if (!visited[w]) {
				dist[w] = dist[s] + 1;
				visited[w] = true;
				path[w] = s;
				q.push(w);
			}
		}
	}
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

void Graph::topologicalSort(int v, stack<int>& sorting) {
	vector < int >path(adj.size());
	vector < bool >visited(adj.size());

	for (int v = 0; v < adj.size(); ++v) {
		visited[v] = false;
	}
	dfs(v, visited, path, sorting);
	/* while (sorting.empty() == false) { */
	/* 	cout << sorting.top() << " "; */
	/* 	sorting.pop(); */
	/* } */
}

void Graph::addWeightedEdge(int u, int v, int w) {
	adj[u].push_back(v);
	weight[u][v] = w;
}

// Dijkstra complexity: extracts min |V| times and decreases key |E| times -
// each cost O(log(V)) using a min heap, so O(V*log(V) + E*log(V)) and
// since E >= V-1 in connected graph then O(E*log(V))
void Graph::dijkstra(int s, vector < int >& path, vector < int >& dist) {
	// Define compare operator for the priority queue
	struct pair_comp {
		constexpr bool operator()(pair<int, int> const& a, pair<int, int> const& b) const noexcept {
			return a.first > b.first;
		}
	};
	// Priority queue of pair<int, int> (cost, node)
	priority_queue < pair<int, int>, vector<pair<int, int>>, pair_comp>q;
	vector < bool >visited(adj.size());

	// Cleanup prior graph traversel
	for (int node = 0; node < adj.size(); ++node) {
		dist[node] = INF;
		visited[node] = false;
		path[node] = -1;
	}
	dist[s] = 0;

	// Push start node to queue
	q.push(make_pair(dist[s], s));

	// Time complexity: O(|E|*log(|V|))
	// O(|V|)*(O(log(|V|) + O(|E|/|V|)*O(log(|V|))
	// O(|V|*log(|V|) + O(|E|*log(|V|)) => O(|E|*log(|V|))
	while (!q.empty()) {  // O(|V|)
		int current_node = q.top().second;
		q.pop(); // O(log(|V|))
		visited[current_node] = true;
		for (auto neighbor : adj[current_node]) { // O(|E|/|V|)
			int cost = dist[current_node] + weight[current_node][neighbor];
			if (!visited[neighbor] && dist[current_node] != INF
				&& cost < dist[neighbor]) {
				dist[neighbor] = cost;
				path[neighbor] = current_node;
				q.push(make_pair(dist[neighbor], neighbor)); // O(log(|V|))
			}
		}
	}
}

vector<int> Graph::dijkstra(int s, int goal, vector<int>& path, vector<int>& dist) {
	// Define compare operator for the priority queue
	struct pair_comp {
		constexpr bool operator()(pair<int, int> const& a, pair<int, int> const& b) const noexcept {
			return a.first > b.first;
		}
	};
	// Priority queue of pair<int, int> (cost, node)
	priority_queue < pair<int, int>, vector<pair<int, int>>, pair_comp>q;
	vector<bool> visited(adj.size());
	vector<int> route;
	// Cleanup prior graph traversel
	for (int node = 0; node < adj.size(); ++node) {
		dist[node] = INF;
		visited[node] = false;
		path[node] = -1;
	}
	dist[s] = 0;

	// Push start node to queue
	q.push(make_pair(dist[s], s));

	while (!q.empty()) {
		int current_node = q.top().second;
		// Early Exit
		if (current_node == goal) {
			route.push_back(current_node); // Traverse back to s
			while (current_node != s) {
				route.push_back(path[current_node]);
				current_node = path[current_node];
			}
			reverse(route.begin(), route.end()); // Reverse path
			return route;
		}
		q.pop();
		visited[current_node] = true;
		for (auto neighbor : adj[current_node]) {
			int cost = dist[current_node] + weight[current_node][neighbor];
			if (!visited[neighbor] && dist[current_node] != INT_MAX
				&& cost < dist[neighbor]) {
				dist[neighbor] = cost;
				path[neighbor] = current_node;
				q.push(make_pair(dist[neighbor], neighbor));
			}
		}
	}
	return route; // Return empty route
}

// Bellman-Ford complexity: O(V*E)
bool Graph::bellman_ford(int s, vector<int>& path, vector<int>& dist) {

	for (int v = 0; v < adj.size(); ++v) {
		dist[v] = INF;
		path[v] = -1;
	}
	dist[s] = 0;

	// for max length of path |V|-1: O(V)
	for (int v = 0; v < adj.size() - 1; ++v) {
		// for each edge in graph: O(E)
		for (int u = 0; u < adj.size(); u++) {
			for (auto v : adj[u]) {
				if (dist[u] + weight[u][v] < dist[v]) {
					dist[v] = dist[u] + weight[u][v];
					path[v] = u;
				}
			}
		}
	}

	for (int u = 0; u < adj.size(); u++) {
		for (auto v : adj[u]) {
			if (dist[u] + weight[u][v] < dist[v]) {
				return false;
			}
		}
	}

	return true;
}

// DAG shortest path complexity: O(V+E) (linear in graph size)
void Graph::dag_shortest_path(int s, vector<int>& path, vector<int>& dist) {
	stack < int >sorting;

	// topologically sort the vertices
	topologicalSort(s, sorting);

	// initialize dist and path
	for (int v = 0; v < adj.size(); ++v) {
		dist[v] = INF;
		path[v] = -1;
	}
	dist[s] = 0;

	while (!sorting.empty()) {
		int u = sorting.top();
		sorting.pop();
		for (auto v : adj[u]) {
			if (dist[u] + weight[u][v] < dist[v]) {
				dist[v] = dist[u] + weight[u][v];
				path[v] = u;
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

void Graph::printw() {
	for (int v = 0; v < adj.size(); ++v) {
		cout << "Adjacency list of vertex " << v;
		for (auto x : adj[v])
			cout << " -> (" << x << ", " << weight[v][x] << ")";
		cout << endl;
	}
}

/* Print Graphs in Graphviz format */
/* Output can be pasted into ex:   */
/* https://dreampuf.github.io/GraphvizOnline/ */

void Graph::print_digraph_graphviz() {
	cout << "digraph G {" << endl;
	for (int v = 0; v < adj.size(); ++v)
	{
		for (auto x : adj[v])
			cout << "  " << v << " -> " << x << " [label=\"" << weight[v][x] << "\"]" << endl;
	}
	cout << "}" << endl;
}

void Graph::print_graph_graphviz() {
	cout << "strict graph G {" << endl;
	for (int v = 0; v < adj.size(); ++v)
	{
		for (auto x : adj[v])
			cout << "  " << v << " -- " << x << endl;
	}
	cout << "}" << endl;
}
