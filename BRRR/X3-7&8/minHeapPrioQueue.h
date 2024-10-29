#pragma once

#include "priority_queue.h"
#include "min_heap.h"

template <typename T>
class MinHeapPrioQueue : public PriorityQueue<T>
{
private:
	MinHeap<T> heap;
public:

	MinHeapPrioQueue() {}

	~MinHeapPrioQueue() {}

	void push(const T& x) override {
		heap.insert(x);
	}

	void pop() override {
		if (empty()) {
			throw runtime_error("Priority queue is empty");
		}
		heap.remove();
	}

	T top() override {
		if (empty()) {
			throw runtime_error("Priority queue is empty");
		}
		return heap.peek();
	}

	bool empty() const override {
		return heap.isEmpty();
	}

	void print() {
		heap.printHeap();
	}
};