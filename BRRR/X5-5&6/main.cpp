
#include <iostream>
#include "Linked_list.h"

int main() {
	Linked_list<int> list;
	list.push_back(1);
	list.push_back(8);
	list.push_back(3);
	list.push_back(11);
	list.push_back(5);

	cout << "The List: ";
	list.print();
	cout << endl;

	cout << "Searching for 11: " << (list.search(11) ? "Found" : "Not Found") << std::endl;

	return 0;
}