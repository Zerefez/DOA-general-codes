#pragma once

#include "Stack.h"

template <typename Object>
class Setstack
{
private:
	Stack<Object> stack;
	Stack<Object> tempstack;

public:
	Setstack();
	~Setstack();
	int size();
	bool empty();
	void clear();
	void display();
	void remove(const Object x);
	bool contains(const Object x);
	void push(const Object x);
};

template<typename Object>
inline Setstack<Object>::Setstack()
{
}

template<typename Object>
inline Setstack<Object>::~Setstack()
{
	clear();
}

template<typename Object>
inline int Setstack<Object>::size()
{
	return stack.size();
}

template<typename Object>
inline bool Setstack<Object>::empty()
{
	return stack.empty();
}

template<typename Object>
inline void Setstack<Object>::clear()
{
	while (!stack.empty())
	{
		stack.pop();
	}
	while (!tempstack.empty())
	{
		tempstack.pop();
	}
}

template<typename Object>
inline void Setstack<Object>::display()
{
	while (!stack.empty()) // while the stack is not empty
	{
		Object temp = stack.pop(); // pop the top element
		cout << temp << " ";
		tempstack.push(temp); // push the top element to the temp stack
	}
	while (!tempstack.empty()) // while the temp stack is not empty
	{
		stack.push(tempstack.pop()); // push the top element back to the stack
	}
	cout << endl;
}

template<typename Object>
inline void Setstack<Object>::remove(const Object x)
{
	while (!stack.empty())
	{
		Object temp = stack.pop(); // pop the top element
		if (temp != x)	// if the top element is not equal to x
		{
			tempstack.push(temp); // push the top element to the temp stack
		}
	}
	while (!tempstack.empty()) // while the temp stack is not empty
	{
		stack.push(tempstack.pop()); // push the top element back to the stack
	}

}

template<typename Object>
inline bool Setstack<Object>::contains(const Object x)
{
	bool found = false;
	while (!stack.empty())
	{
		Object temp = stack.pop(); // pop the top element
		if (temp == x) // if the top element is equal to x
		{
			found = true;
		}
		tempstack.push(temp); // push the top element to the temp stack
	}
	while (!tempstack.empty())
	{
		stack.push(tempstack.pop()); // push the top element back to the stack
	}
	return found;
}

template<typename Object>
inline void Setstack<Object>::push(const Object x)
{
	if (!contains(x)) {
		cout << "Pushing -> " << x << endl;
		stack.push(x);
	}
	else {
		cout << "Cannot push duplicate element: " << x << endl;
	}

}
