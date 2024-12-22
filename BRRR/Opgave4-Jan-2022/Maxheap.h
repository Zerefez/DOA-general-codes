#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename Comparable>
class MaxHeap {	
public:
	MaxHeap(int capacity);
	~MaxHeap();
	bool isEmpty() const; //is the heap empty?
	int size() const; //number of elements in the heap
	void insert(const Comparable& x); //add an element to the heap
	const Comparable& findMax() const; // find the maximum element of the heap
	void deleteMax(); //delete the maximum element of the heap
private:
	int currentSize; 
	vector<Comparable> array;
};

template <typename Comparable>	
MaxHeap<Comparable>::MaxHeap(int capacity) : array(capacity), currentSize(0) {}

template <typename Comparable>
MaxHeap<Comparable>::~MaxHeap() {}

template <typename Comparable>
bool MaxHeap<Comparable>::isEmpty() const {
	return currentSize == 0;
}

template <typename Comparable>
int MaxHeap<Comparable>::size() const {
	return currentSize;
}

template <typename Comparable>
void MaxHeap<Comparable>::insert(const Comparable& x) {
	if (currentSize == array.size() - 1) {
		array.resize(array.size() * 2);
	}
	int hole = ++currentSize;
	for (; hole > 1 && x > array[hole / 2]; hole /= 2) {
		array[hole] = array[hole / 2];
	}
	array[hole] = x;
}

template <typename Comparable>
const Comparable& MaxHeap<Comparable>::findMax() const {
	if (isEmpty()) {
		throw runtime_error("Heap is empty");
	}
	return array[1];
}

template <typename Comparable>
void MaxHeap<Comparable>::deleteMax() {
	if (isEmpty()) {
		throw runtime_error("Heap is empty");
	}
	array[1] = array[currentSize--];
	int hole = 1;
	int child;
	Comparable tmp = array[hole];
	for (; hole * 2 <= currentSize; hole = child) {
		child = hole * 2;
		if (child != currentSize && array[child + 1] > array[child]) {
			child++;
		}
		if (array[child] > tmp) {
			array[hole] = array[child];
		}
		else {
			break;
		}
	}
	array[hole] = tmp;
}




