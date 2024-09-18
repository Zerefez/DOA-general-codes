#pragma once


#include <iostream>
#include <cassert>	

using namespace std;

template <typename Object>
class Stack
{
private:
	Object* array;
	int array_size;
	int stack_size;

public:
	Stack();
	~Stack();
	int size();
	bool empty();
	void clear();
	void push(const Object x);
	Object pop();
	Object top();

};

template<typename Object>
inline Stack<Object>::Stack()
{
	array_size = 100;
	stack_size = 0;
	array = new Object[array_size];
}

template<typename Object>
inline Stack<Object>::~Stack()
{
	clear();
}

template<typename Object>
inline int Stack<Object>::size()
{
	return stack_size;
}

template<typename Object>
inline bool Stack<Object>::empty()
{
	return size() == 0;
}

template<typename Object>
inline void Stack<Object>::clear()
{
	delete[] array;
	array = new Object[array_size];
	stack_size = 0;
}

template<typename Object>
inline void Stack<Object>::push(const Object x)
{
	if (stack_size == array_size)
	{
		cout << "Doubling array size" << endl;
		Object* temp = new Object[array_size * 2];
		for (int i = 0; i < array_size; i++)
		{
			temp[i] = array[i];
		}
		delete[] array;
		array = temp;
		array_size *= 2;
	}
	array[stack_size] = x;
	stack_size++;
}

template<typename Object>
inline Object Stack<Object>::pop()
{
	stack_size--;
	return array[stack_size];
}

template<typename Object>
inline Object Stack<Object>::top()
{
	return array[stack_size - 1];
}
