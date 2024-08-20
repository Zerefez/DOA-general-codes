
#include "Vector.h"
#include <iostream>

int main() {

	Vector v;
	v.insert(5);
	v.insert(3);
	v.insert(7);
	v.insert(1);
	v.insert(9);
	v.insert(2);
	v.insert(4);
	v.insert(6);
	v.insert(8);
	v.insert(0);

	v.print();

	cout << "Max: " << v.findMax() << endl;
	cout << "Size: " << v.size() << endl;
	cout << "Deleting max: " << v.deleteMax() << endl;
	cout << "Max: " << v.findMax() << endl;
	cout << "Size: " << v.size() << endl;
	return 0;
}