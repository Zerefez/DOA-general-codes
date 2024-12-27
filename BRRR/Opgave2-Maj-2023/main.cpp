#include <iostream>
#include "binaryheap.h"

int main() {

	BinaryHeap<int> bh;
	bh.insert(5);
	bh.insert(3);
	bh.insert(2);
	bh.insert(7);
		
	cout << "Min element: " << bh.findMin() << endl;
	bh.deleteMin();
	cout << "Min element: " << bh.findMin() << endl;
	bh.changePriority(3, 5);
	cout << "Min element: " << bh.findMin() << endl;
	bh.deleteMin();
	bh.changePriority(5, 7);
	cout << "Min element: " << bh.findMin() << endl;
	bh.changePriority(7, 3);
	cout << "Min element: " << bh.findMin() << endl;
    return 0;
}
