

#pragma once
#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_

#include <stdexcept>
#include <vector>

using namespace std;

template <typename Comparable>
class BinaryHeap {
private:
	int currentSize;	        // Number of elements in heap
	vector<Comparable> array;	// The heap array

	void buildHeap();
	void minHeapify(int hole);

public:
	BinaryHeap(int capacity = 100) : array(capacity + 1), currentSize(0) {};

	BinaryHeap(const vector<Comparable>& items) {
		array.resize(items.size() + 10);
		for (int i = 0; i < items.size(); ++i)
			array[i + 1] = items[i];
		currentSize = items.size() + 1;
		buildHeap();
	}

	bool isEmpty() const { return currentSize == 0; }

	void insert(const Comparable& x);
	const Comparable& findMin() const;
	void deleteMin();
	void deleteMin(Comparable& minItem);
	void changePriority(Comparable fromP, Comparable toP);


};

template<typename Comparable>
void BinaryHeap<Comparable>::changePriority(Comparable fromP, Comparable toP){
	int hole = 0;
	for (int i = 1; i < currentSize; i++) {
		if (array[i] == fromP) {
			hole = i;
			break;
		}
	}
	if (hole == 0) {
		throw underflow_error("Element not found");
	}
	array[hole] = toP;
	minHeapify(hole);
}

#include "binaryheap.tpp"

#endif
