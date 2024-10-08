#include <iostream>
#include <sstream>
#include <string>

#include "binary_heap.h"
using namespace std;

// Test program
int main() {
	int minItem = 10000;	// same number of digits
	int maxItem = 99999;
	BinaryHeap<int> h;
	int x;

	/* Insert all integers i between min and max out of order. */
	for (int i = 37; i != 0; i = (i + 37) % maxItem) {
		if (i >= minItem) {
			h.insert(i);
		}
	}

	for (int i = minItem; i < maxItem; ++i) {
		h.deleteMin(x);
		if (x != i) {
			cout << "Oops! " << i << endl;
		}
	}

	cout << "If nothing was printed before, no error!" << endl;

	return 0;
}
