#pragma once
#ifndef _LIST_H_
#define _LIST_H_

class List {
private:
	// A basic simple linked list node.
	struct Node {
		int    value;
		Node* next;
	};

	int   theSize;
	Node* head;
	Node* tail; // previous sentinel

public:
	List();
	~List();
	int size();
	bool empty();
	void clear();
	void push_front(int x);
	void insert(int x, int pos);
	int find_kth(int pos);
	int pop_front();
	int remove(int pos);
};

#endif
