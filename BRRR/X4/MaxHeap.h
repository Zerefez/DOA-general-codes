#pragma once
class MaxHeap
{
public:
	// is the heap empty
	virtual bool isEmpty() const = 0;

	// number of elements in the heap
	virtual int size() const = 0;

	// add an element to the hea
	virtual void insert(const int x) = 0;

	// find the maximum element in the heap
	virtual const int findMax() const = 0;

	// delete and return the maximum element of the heap
	virtual int deleteMax() = 0;
};

