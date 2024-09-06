#pragma once

#include <vector>

using namespace std;


class Book
{
public:
		int ID;
		int category;
		bool borrowed;

		Book(int i, int c) : ID(i), category(c), borrowed(false) {}
};

class Library
{
public:
	void addBook(int, int);
	void displayBorrowedBooks();
	void displayAllBooks();
	bool returnBook(int);
	bool borrowBook(int);
	void displayAvailableBooks();
	int countBooksInCategory(int);

private:
	vector<Book> books ;

	void issueBalanceWarning(int);

};

