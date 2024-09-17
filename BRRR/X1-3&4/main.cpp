
#include "Linked_list.h"
#include "Linked_list.cpp"
#include <iostream>
#include <vector>
using namespace std;

int main() {

	Linked_list<int> list;
	list.push_back(1);
	list.push_back(8);
	list.push_back(3);
	list.push_back(11);
	list.push_back(5);

	cout << "The Original list: ";
	list.print();
	cout << endl;

	cout << "Size: " << list.size() << endl;
	cout << "First element: " << list.find(0) << endl;
	cout << "Third element: " << list.find(3) << endl;
	cout << "Last element: " << list.find(list.size() - 1) << endl;
	cout << endl;

	list.insert(0, 24);
	list.insert(3, 6);
	list.insert(list.size(), 23);
	cout << "Insert 24 to the beginning." << endl;
	cout << "Insert 6 to fourth element." << endl;
	cout << "Insert 23 to last element." << endl;

	cout << "The new list (after insertions): ";
	list.print();
	cout << endl;

	list.remove(0);
	list.remove(4);
	list.remove(list.size() - 1);

	cout << "Remove element from the beginning." << endl;
	cout << "Remove the fifth element." << endl;
	cout << "Remove the last element." << endl;
	cout << endl;

	cout << "The new list (after removing): ";
	list.print();
	cout << endl;

	cout << "Reverse the list: ";
	list.reverse();
	list.print();
	cout << endl;

	list.contains(3);
	cout << endl;

	cout << "Empty the list: " << list.empty() << endl;

	return 0;
}