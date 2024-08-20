#pragma once
#include "MaxHeap.h"
#include <vector>
#include <iostream>

using namespace std;

class Vector :public MaxHeap
{
public:
	// is the heap empty
	virtual bool isEmpty() const override;

	// number of elements in the heap
	virtual int size() const override;

	// add an element to the hea
	virtual void insert(const int x) override;

	// find the maximum element in the heap
	virtual const int findMax() const override;

	// delete and return the maximum element of the heap
	virtual int deleteMax() override;

	// print the heap
	void print() const;

private:
	vector<int> heap;
};

