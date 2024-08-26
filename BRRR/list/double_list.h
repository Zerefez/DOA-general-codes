#pragma once

#ifndef _LIST_H_
#define _LIST_H_

template <typename Object>
class List {
private:
	struct Node {
		Object  data;
		Node* next;
		Node* prev;
	};
	int   theSize;
	Node* head;
	Node* tail;

public:
	List() {
		theSize = 0;
		head = new Node; tail = new Node;
		head->next = tail;
		tail->prev = head;
		head->prev = tail->next = nullptr;
	}

	~List() { clear(); delete head; delete tail; }

	int size() { return theSize; }
	bool empty() { return (size() == 0); }

	void clear();
	void push_front(const Object x);
	void push_back(const Object x);
	Object pop_front();
	Object pop_back();
	Object find_kth(int pos);
};

#include "double_list.tpp"

#endif
