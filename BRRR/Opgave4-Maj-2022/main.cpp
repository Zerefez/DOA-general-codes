
#include "Maxheap.h"
#include <iostream>

using namespace std;


int main() {

	MaxHeap heap(10);
	heap.insert(10);
	heap.insert(20);
	heap.insert(30);
	heap.insert(40);
	heap.insert(50);

	heap.print();
	cout << "Heap size: " << heap.size() << endl;

	cout << "Max: " << heap.findMax() << endl;
	heap.deleteMax();

	heap.print();

	cout << "Max: " << heap.findMax() << endl;
	heap.deleteMax();
	heap.print();

	cout << "Is heap empty: " << heap.isEmpty() << endl;


	return 0;
}
