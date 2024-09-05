
#pragma once

#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <cassert>

template <typename Object>
class Queue {
private:
	int N;
	int head, tail, size;
	Object* data;

public:
	Queue(int capacity) {
		data = new Object[capacity];
		N = capacity;
		head = N;
		size = tail = 0;
	}

	~Queue() { delete[] data; }

	bool empty() { return (size == 0); }

	Object front() {
		assert(empty() == false);
		return data[head % N];
	}

	Object get() {
		assert(empty() == false);
		head = head % N;
		Object x = data[head++];
		size--;
		return x;
	}

	void put(const Object x) {
		assert(size < N);
		data[tail] = x;
		tail = (tail + 1) % N;
		size++;
	}
};

#endif
