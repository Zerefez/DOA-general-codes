#include "graph_class.h"


int main() {

	// NEW!!! Adjacency matrix with weights

	std::vector<std::vector<int>> dataLossMatrix = {
	{0,    50,  40, 160, 160, 160, 160, 160},
	{55,    0, 160, 160,  20,  40, 160, 160},
	{35,  160,   0, 160,  45, 160, 160, 160},
	{160, 160, 160,   0, 160,  10, 160,  30},
	{160,  35,  55, 160,   0,  25,  60, 160},
	{160,  60, 160,   5,  10,   0,  85, 160},
	{160, 160, 160, 160,  85,  70,   0, 160},
	{160, 160, 160,  35, 160, 160, 160,   0}
	};

	// Use new constructor
	Graph graph2(dataLossMatrix);

	// Compute all pairs shortest paths
	Matrix<int> dists2(8, 8);
	Matrix<int> paths2(8, 8);
	graph2.allPairs(paths2, dists2);

	// Print result
	for (int i = 0; i < 7; i++) {
		cout << i << ": ";
		for (int j = 0; j < 7; j++)
			cout << std::setw(3) << dists2[i][j] << " ";
		cout << endl;
	}

	// Find lowest incoming data loss (sum values of each column)
	for (int i = 0; i < 7; i++) {
		int sum = 0;
		for (int j = 0; j < 7; j++)
			sum += dists2[j][i];
		cout << "Incoming data loss at node " << i << " is " << sum << endl;
	}

	return 0;
}
