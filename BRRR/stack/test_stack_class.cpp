using namespace std;
#include <iostream>
#include "stack_class.h"

int main(int argc, char* argv[]) {
	Stack<int>* stack = new Stack<int>();
	stack->push(10);
	stack->push(5);
	stack->push(3);
	stack->push(7);

	cout << "Top element:    " << stack->top() << endl;
	while (stack->empty() == false) {
		cout << "Next element:   " << stack->pop() << endl;
	}
	cout << "Stack is empty?  " << stack->empty() << endl;

	delete stack;
}
