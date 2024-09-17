#include "Queue.h"
#include <iostream>

int main()
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);



	q.pop();
	q.pop();
	q.pop();
	q.pop();

	return 0;
}
