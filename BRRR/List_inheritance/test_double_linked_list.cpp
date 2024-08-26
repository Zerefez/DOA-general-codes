using namespace std;
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "simple_list.h"
#include "double_linked_list.h"

int main(int argc, char* argv[]) {
	DoubleLinkedList<int> list = DoubleLinkedList<int>();

	list.push_front(10);
	list.push_front(5);
	list.push_front(3);
	list.push_front(7);
	list.push_back(11);

	cout << "List size:      " << list.size() << endl;
	cout << "First element:  " << list.find_kth(0) << endl;
	cout << "Second element: " << list.find_kth(1) << endl;
	cout << "Last element Pop'd: " << list.pop_back() << endl;
	while (list.empty() == false) {
		cout << "Next element:   " << list.pop_front() << endl;
	}
	cout << "List is empty?  " << list.empty() << endl;

	List<float>* listf = new DoubleLinkedList<float>();
	listf->push_front(1.1);
	listf->push_front(-0.5);
	listf->push_front(M_PI);
	listf->push_front(7.0);

	cout << "List size:      " << listf->size() << endl;
	cout << "First element:  " << listf->find_kth(0) << endl;
	cout << "Second element: " << listf->find_kth(1) << endl;
	while (listf->empty() == false) {
		cout << "Next element:   " << listf->pop_front() << endl;
	}
	cout << "List is empty?  " << listf->empty() << endl;

	delete listf;

	return 0;
}
