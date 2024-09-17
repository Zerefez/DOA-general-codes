#pragma once

#include <cassert>
#include "List.h"

using namespace std;

template <typename Object>
class Linked_list : public List<Object>
{
private:
	struct Node
	{
		Object data;
		Node* next;
		Node* prev;
		Node(const Object& d = Object(), Node* n = NULL, Node* p = NULL) : data(d), next(n), prev(p) {}

	};
	int list_size;
	Node* head;
	Node* tail;
public:
	Linked_list();
	~Linked_list();
	int size();
	bool empty();
	void clear();
	void insert(int pos, const Object x);
	void remove(int pos);
	void push_back(const Object x);
	void push_front(const Object x);
	void reverse();
	void print();
	bool contains(const Object x);
	Object pop_back();
	Object pop_front();
	Object find(int pos);
};


