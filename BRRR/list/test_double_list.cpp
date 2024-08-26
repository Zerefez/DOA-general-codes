using namespace std;
#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <iostream>
#include "double_list.h"

int main(int argc, char* argv[]) {
	List<int>* list = new List<int>();
	list->push_front(10);
	list->push_front(5);
	list->push_back(3);
	list->push_back(7);

	cout << "List size:      " << list->size() << endl;
	while (list->empty() == false) {
		cout << "Next element:   " << list->pop_front() << endl;
	}
	cout << "List is empty?  " << list->empty() << endl;

	delete list;

	List<float>* listf = new List<float>();
	listf->push_front(1.1);
	listf->push_front(-0.5);
	listf->push_back(M_PI);
	listf->push_back(7.0);

	cout << "List size:      " << listf->size() << endl;
	while (listf->empty() == false) {
		cout << "Next element:   " << listf->pop_front() << endl;
	}
	cout << "List is empty?  " << listf->empty() << endl;

	delete listf;
}
