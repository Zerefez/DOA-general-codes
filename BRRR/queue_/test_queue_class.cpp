using namespace std;
#include <iostream>
#include "queue_class.h"

int main(int argc, char* argv[]) {
	Queue<int>* queue = new Queue<int>();
	queue->put(10);
	queue->put(5);
	queue->put(3);
	queue->put(7);

	cout << "Front element:  " << queue->front() << endl;
	while (queue->empty() == false) {
		cout << "Next element:   " << queue->get() << endl;
	}
	cout << "Queue is empty?  " << queue->empty() << endl;

	delete queue;
}
