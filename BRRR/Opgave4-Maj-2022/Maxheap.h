
#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;


class MaxHeap {
public:
	MaxHeap(int capacity) : currentSize(0) {
		array.resize(capacity + 1);
	}
	~MaxHeap(){
		array.clear();
	}
	bool isEmpty() const //is the heap empty?
	{ 
		return currentSize == 0;
	}
	int size() const //number of elements in the heap
	{
		return currentSize;
	}
	void insert(const int& x) //add an element to the heap
	{
		if (currentSize == array.size() - 1)
		{
			array.resize(array.size() * 2);
		}
		int hole = ++currentSize;
		for (; hole > 1 && x > array[hole / 2]; hole /= 2)
		{
			array[hole] = array[hole / 2];
		}
		array[hole] = x;

	}
	const int& findMax() const // find the maximum element of the heap
	{
		if (isEmpty())
		{
			throw std::runtime_error("Heap is empty.");
		}
		
		std::vector<int>::const_iterator start = array.begin() + 1;
		std::vector<int>::const_iterator end = array.begin() + currentSize + 1;
		std::vector<int>::const_iterator maxIt = start;
		for (std::vector<int>::const_iterator it = start; it != end; ++it)
		{
			if (*it > *maxIt)
			{
				maxIt = it;
			}
		}

		return *maxIt;
		
	}
	void deleteMax() //delete the maximum element of the heap
	{
		vector<int>::iterator it = array.begin();
		int max = *it;
		for (it = array.begin(); it != array.end(); ++it)
		{
			if (*it > max)
				max = *it;
		}
		int hole = 1;
		int lastElement = array[currentSize--];
		int child;
		for (; hole * 2 <= currentSize; hole = child)
		{
			child = hole * 2;
			if (child != currentSize && array[child + 1] > array[child])
				child++;
			if (array[child] > lastElement)
				array[hole] = array[child];
			else
				break;
		}
		array[hole] = lastElement;	
	}

	void print() const
	{
		for (int i = 1; i <= currentSize; i++)
			cout << array[i] << " ";
		cout << endl;
	}

private:
	int currentSize;
	vector<int> array;
};




