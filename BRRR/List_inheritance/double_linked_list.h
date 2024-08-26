#pragma once
#pragma once

#include <cassert>
#include "simple_list.h"

template <typename Object>
class DoubleLinkedList :
	public List<Object>
{
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

	DoubleLinkedList() {
		theSize = 0;
		head = new Node; tail = new Node;
		head->next = tail;
		tail->prev = head;
		head->prev = tail->next = nullptr;
	}

	~DoubleLinkedList() {
		clear();
		delete head;
		delete tail;
	}

	int size() { return theSize; }
	bool empty() { return (size() == 0); }

	void clear() {
		Node* p = head->next;
		while (p != tail) {
			Node* t = p->next;
			delete p;
			p = t;
		}
		head->next = tail;
		tail->prev = head;
	}

	void push_front(const Object x) {
		Node* p = new Node;
		Node* t = head->next;
		p->data = x;
		p->prev = head;
		p->next = t;
		t->prev = p;
		head->next = p;
		theSize++;
	}

	void push_back(const Object x) {
		Node* p = new Node;
		Node* t = tail->prev;
		p->data = x;
		p->prev = t;
		p->next = tail;
		t->next = p;
		tail->prev = p;
		theSize++;
	}

	Object pop_front() {
		Node* p = head->next;
		Node* t = p->next;
		Object x = p->data;
		t->prev = head;
		head->next = t;
		theSize--;
		delete p;
		return x;
	}

	Object pop_back() {
		Node* p = tail->prev;
		Node* t = p->prev;
		Object x = p->data;
		t->next = tail;
		tail->prev = t;
		theSize--;
		delete p;
		return x;
	}

	Object find_kth(int pos) {
		assert(pos >= 0 && pos < theSize);
		Node* p = head->next;
		while (pos > 0) {
			p = p->next;
			pos--;
		}
		return p->data;
	}
};
