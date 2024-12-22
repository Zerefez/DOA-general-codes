
#include "Maxheap.h"
#include <iostream>

using namespace std;


int main() {

	MaxHeap<int> heap(10);
	heap.insert(10);
	heap.insert(20);
	heap.insert(30);
	heap.insert(40);
	heap.insert(50);

	cout << "Heap size: " << heap.size() << endl;	

	cout << "Max: " << heap.findMax() << endl;
	heap.deleteMax();
	cout << "Max: " << heap.findMax() << endl;
	heap.deleteMax();

	cout << "Is heap empty: " << heap.isEmpty() << endl;


	return 0;
}
