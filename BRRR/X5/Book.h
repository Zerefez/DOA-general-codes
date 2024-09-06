#pragma once
class Book
{
public:
	int ID;
	int category;
	bool borrowed;

	Book(int i, int c) : ID(i), category(c), borrowed(false) {}
};
