#include "Library.h"
#include <iostream>
#include <vector>

using namespace std;

void Library::addBook(int id, int cat)
{
	books.emplace_back(Book(id, cat));
	issueBalanceWarning(cat);
}

void Library::displayBorrowedBooks()
{
	for (auto& book : books)
	{
		if (book.borrowed)
		{
			cout  << "Book ID: " << book.ID << " Category: " << book.category << endl;
		}
	}
}

void Library::displayAllBooks()
{
	for (auto& book : books)
	{
		cout << "Book ID: " << book.ID << " Category: " << book.category << endl;
	}
}

bool Library::returnBook(int id)
{
	for (auto& book : books)
	{
		if (book.ID == id && book.borrowed) {
			return book.borrowed = true;
		}
	}
	return false;
}

bool Library::borrowBook(int id)
{
	for (auto& book : books)
	{
		if (book.ID == id && !book.borrowed) {
			return book.borrowed = true;
		}
	}
	return false;
}

void Library::displayAvailableBooks()
{
	for (auto& book : books)
	{
		if (!book.borrowed)
		{
			cout << "Book ID: " << book.ID << " Category: " << book.category << endl;
		}
	}
}

int Library::countBooksInCategory(int cat)
{
	int count = 0;
	for (auto& book : books)
	{
		if (book.category == cat)
		{
			count++;
		}
	}
	return count;
}

void Library::issueBalanceWarning(int cat)
{
	int count[16] = { 0 }; // Array to store counts for each category

	// Count the number of books in each category
	for (const auto& book : books) {
		if (book.category >= 0 && book.category < 16) {
			count[book.category]++;
		}
	}

	// Calculate the total number of categories with books
	int totalCategories = 0;
	int totalBooks = 0;

	for (int i = 0; i < 16; ++i) {
		if (count[i] > 0) {
			totalCategories++;
			totalBooks += count[i];
		}
	}

	// Calculate the average number of books per category
	double average = (totalCategories > 0) ? static_cast<double>(totalBooks) / totalCategories : 0;

	// Debugging outputs
	std::cout << "Total Categories with Books: " << totalCategories << std::endl;
	std::cout << "Total Books: " << totalBooks << std::endl;
	std::cout << "Average Books per Category: " << std::fixed  << average << std::endl;

	// Check each category and issue warnings if necessary
	for (int i = 0; i < 16; ++i) {
		if (count[i] >= 2 * average) {
			std::cout << "Warning: Category " << i << " has " << count[i] << " books, which is above average." << std::endl;
		}
	}
}
