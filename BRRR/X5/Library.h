#pragma once

#include <vector>
#include "Book.h"

using namespace std;


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

