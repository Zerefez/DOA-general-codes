#include <cassert>

template <typename Object>
void List<Object>::clear() {
	Node *p = head->next;
	while (p != tail) {
		Node *t = p->next;
		delete p;
		p = t;
		head->next = t;
	}
}

template <typename Object>
void List<Object>::push_front(const Object x) {
	Node *p = new Node;
	p->data = x;
	p->next = head->next;
	head->next = p;
	theSize++;
}

template <typename Object>
Object List<Object>::pop_front() {
	Node *p = head->next;
	Object x = p->data;
	head->next = p->next;
	theSize--;
	delete p;
	return x;
}

template <typename Object>
Object List<Object>::find_kth(int pos) {
	assert(pos >= 0 && pos < theSize);
	Node *p = head->next;
	while (pos > 0) {
		p = p->next;
		pos--;
	}
	return p->data;
}
