#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "../List/double_list.h"

template <typename Object>
class Queue {
private:
	List<Object>* list;

public:
	Queue() {
		list = new List<Object>();
	}

	~Queue() { delete list; }

	bool empty() { return (list->size() == 0); }
	Object front() { return list->find_kth(0); };
	Object get() { return list->pop_front(); };

	void put(const Object x) {
		list->push_back(x);
	};
};

#endif
