#include <cassert>
#include "simple_int_list.h"

List::List() {
	theSize = 0;
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->next = nullptr;
}

List::~List() {
	clear();
	delete head;
	delete tail;
}

int List::size() {
	return theSize;
}

bool List::empty() {
	return (size() == 0);
}

void List::clear() {
	Node* p = head->next;
	while (p != tail) {
		Node* t = p->next;
		delete p;
		p = t;
		head->next = t;
	}
}

void List::push_front(int x) {
	Node* p = new Node;
	p->value = x;
	p->next = head->next;
	head->next = p;
	theSize++;
}

void List::insert(int x, int pos) {
	assert(pos >= 0 && pos <= theSize);
	Node* p = head->next;
	while (pos > 1) {
		p = p->next;
		pos--;
	}
	Node* q = new Node;
	q->value = x;
	q->next = p->next;
	p->next = q;
	theSize++;
}

int List::find_kth(int pos) {
	assert(pos >= 0 && pos < theSize);
	Node* p = head->next;
	while (pos > 0) {
		p = p->next;
		pos--;
	}
	return p->value;
}

int List::pop_front() {
	Node* p = head->next;
	int x = p->value;
	head->next = p->next;
	theSize--;
	delete p;
	return x;
}

int List::remove(int pos) {
	assert(pos >= 0 && pos < theSize);
	Node* p = head->next;
	while (pos > 1) {
		p = p->next;
		pos--;
	}
	Node* q = p->next;
	int x = q->value;
	p->next = q->next;
	theSize--;
	delete q;
	return x;
}
