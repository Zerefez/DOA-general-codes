#pragma once
#pragma once

#include <cassert>
#include "simple_list.h"

template <typename Object>
class LinkedList :
	public List<Object>
{
private:

	struct Node {
		Object  data;
		Node* next;
	};
	int   theSize;
	Node* head;
	Node* tail;

	Node* find_last_node() {
		Node* last = head;
		while (last->next != tail) {
			last = last->next;
		}
		return last;
	}

public:

	LinkedList() {
		theSize = 0;
		head = new Node; tail = new Node;
		head->next = tail;
		tail->next = nullptr;
	}

	~LinkedList() {
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
			head->next = t;
		}
	}

	void push_front(const Object x) {
		Node* p = new Node;
		p->data = x;
		p->next = head->next;
		head->next = p;
		theSize++;
	}

	void push_back(const Object x) {
		// Locate last node:
		Node* last = head;
		while (last->next != tail) {
			last = last->next;
		}
		// Add new node and set its next to tail.
		Node* p = new Node;
		p->data = x;
		p->next = tail;
		// Set last node to new node.
		last->next = p;
		theSize++;
	}

	Object pop_front() {
		Node* p = head->next;
		Object x = p->data;
		head->next = p->next;
		theSize--;
		delete p;
		return x;
	}

	Object pop_back() {
		assert(theSize > 0);
		if (theSize == 1) {
			return pop_front();
		}
		assert(theSize >= 2);
		Node* second_to_last = head;
		while (second_to_last->next->next != tail) {
			second_to_last = second_to_last->next;
		}
		Object x = second_to_last->next->data;
		second_to_last->next = tail;
		theSize--;
		delete second_to_last->next;
		return x;
	}

	Object find_kth(int pos) {
		assert(pos >= 0 && pos < theSize);
		Node* p = head->next;
		while (pos > 0) {
			p = p->next;
			pos--;
		}
		assert(pos >= 0 && p != NULL);
		return p->data;
	}
};
