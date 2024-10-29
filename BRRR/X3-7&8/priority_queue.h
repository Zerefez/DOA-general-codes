#pragma once

template<class T>
class PriorityQueue
{
public:
	virtual void push(const T& x) = 0;
	virtual void pop() = 0;
	virtual T top() = 0;
	virtual bool empty() const = 0;
	virtual ~PriorityQueue() {}
};

