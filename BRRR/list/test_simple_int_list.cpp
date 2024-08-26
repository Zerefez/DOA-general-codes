using namespace std;

#include <iostream>

#include "simple_int_list.h"

int main(int argc, char* argv[]) {
	List* list = new List();

	list->push_front(10);
	list->push_front(5);
	list->push_front(3);
	list->push_front(7);

	cout << "List size      : " << list->size() << endl;
	cout << "First element  : " << list->find_kth(0) << endl;
	cout << "Second element : " << list->find_kth(1) << endl;
	cout << "Removed element: " << list->remove(1) << endl;
	cout << "Second element : " << list->find_kth(1) << endl;
	list->insert(20, 1);
	cout << "Added element  : " << 20 << endl;
	cout << "Second element : " << list->find_kth(1) << endl;

	while (list->empty() == false) {
		cout << "Next element:    " << list->pop_front() << endl;
	}
	cout << "List is empty?   " << list->empty() << endl;

	delete list;
}
