#pragma once

#include <iostream>
using namespace std;

template <typename Object>
class List
{
public:

	virtual int size() = 0;
	virtual bool empty() = 0;
	virtual void clear() = 0;
	virtual void insert(int pos, const Object x) = 0;
	virtual void remove(int pos) = 0;
	virtual void push_back(const Object x) = 0;
	virtual void push_front(const Object x) = 0;
	virtual Object pop_back() = 0;
	virtual Object pop_front() = 0;
	virtual Object find(int pos) = 0;

};
