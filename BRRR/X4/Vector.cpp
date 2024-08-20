#include "Vector.h"
#include <iostream>

bool Vector::isEmpty() const
{
	return heap.empty();
}

int Vector::size() const
{
	return heap.size();
}

void Vector::insert(const int x)
{
	heap.push_back(x);
}

const int Vector::findMax() const
{
	if (isEmpty())
	{
		cout << "Heap is empty" << endl;
		return -1;
	}
	int max = heap[0];
	for (int i = 1; i < heap.size(); i++)
	{
		if (heap[i] > max)
		{
			max = heap[i];
		}
	}
	return max;
}

int Vector::deleteMax()
{
	if (isEmpty())
	{
		cout << "Heap is empty" << endl;
		return -1;
	}
	int max = heap[0];
	int maxIndex = 0;
	for (int i = 1; i < heap.size(); i++)
	{
		if (heap[i] > max)
		{
			max = heap[i];
			maxIndex = i;
		}
	}
	heap.erase(heap.begin() + maxIndex);
	return max;
}

void Vector::print() const
{
	cout << "Heap:";

	for (int i = 0; i < heap.size(); i++)
	{
		cout << heap[i] << " ";
	}
	cout << endl;
}
