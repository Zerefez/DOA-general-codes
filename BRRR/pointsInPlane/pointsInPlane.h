
#pragma once

#include <iostream>
#include <vector>
#include <random>

using namespace std;

struct Point {
	double x;
	double y;
};

class PointsInPlane {
private:
	int _width;
	int _height;
	vector<Point> points;
	vector<vector<pair<int, int>>> weightedGraph;

	double calculateDistance(const Point& point1, const Point& point2)
	{
		return abs(point1.x - point2.x) + abs(point1.y - point2.y);
	}

public:
	PointsInPlane(int width, int height)
	{
		_width = width;
		_height = height;
	}

	void generateRandomPoints()
	{
		srand(time(NULL));
		points.clear();

		for (int i = 0; i < 20; i++)
		{
			Point p;
			p.x = rand() % (_width + 1);
			p.y = rand() % (_height + 1);
			points.push_back(p);
		}
	}

	void convertToWeightedGraph()
	{
		vector<vector<pair<int, int>>> convertedGraph(points.size());

		for (int i = 0; i < points.size(); i++)
		{
			for (int j = 0; j < points.size(); j++)
			{
				if (i != j)
				{
					double distance = calculateDistance(points[i], points[j]);
					convertedGraph[i].push_back({ j, distance });
				}
			}
		}

		weightedGraph = convertedGraph;
	}

	int primMST() {
		int mst_wt = 0;	// Initialize result
		vector <int>parent(points.size());	// Array to store MST
		vector <int>key(points.size());	// Values to pick minimum weight edge in cut
		vector <bool>visited(points.size());	// To represent set of vertices included

		// Initialize all keys as INFINITE
		for (int i = 0; i < points.size(); i++) {
			key[i] = INT_MAX, visited[i] = false;
		}

		// Always include first 1st vertex in MST, make sure it is picked first.
		key[0] = 0;
		parent[0] = -1;				// First node is always root of MST

		// The MST will have V vertices
		for (int count = 0; count < points.size(); count++) {
			// Pick the minimum key vertex not yet included in MST
			int min = INT_MAX, u;
			for (int v = 0; v < points.size(); v++) {
				if (visited[v] == false && key[v] < min) {
					min = key[v], u = v;
				}
			}
			// Add the picked vertex to the MST Set
			visited[u] = true;
			if (u != 0) {
				mst_wt += min;
				//cout << u << " - " << parent[u] << ", ";
			}
			// Update key/parent of the adjacent vertices of the picked vertex.
			for (auto& neighbor : weightedGraph[u]) {
				int v = neighbor.first;
				int weight = neighbor.second;
				if (!visited[v] && weight < key[v]) {
					parent[v] = u, key[v] = weight;
				}
			}
		}
		return mst_wt;
	}

	void print() {
		for (size_t i = 0; i < weightedGraph.size(); ++i) {
			cout << "Vertex " << i << " connects to:" << endl;
			for (const auto& neighbor : weightedGraph[i]) {
				int v = neighbor.first;
				int weight = neighbor.second;
				cout << "  Vertex " << v << ", Weight: " << weight << endl;
			}
			cout << endl;
		}
	}
};
