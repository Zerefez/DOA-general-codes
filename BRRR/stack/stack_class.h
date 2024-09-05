#pragma once
#ifndef _STACK_H_
#define _STACK_H_

#include "../list/double_list.h"

template <typename Object>
class Stack {
private:
	List<Object>* list;

public:
	Stack() {
		list = new List<Object>();
	}

	~Stack() { delete list; }

	bool empty() { return (list->size() == 0); }
	Object top() { return list->find_kth(0); }
	Object pop() { return list->pop_front(); }

	void push(const Object x) {
		list->push_front(x);
	}
};

#endif
