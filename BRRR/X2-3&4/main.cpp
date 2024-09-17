#include <iostream>
#include "Stack.h"

using namespace std;

int main() {

	Stack<int> s;
	for (size_t i = 0; i < 201; i++)
	{
		s.push(i);

	}

	return 0;
}