
#include "Library.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    Library myLibrary;

    // Adding books to the library
    myLibrary.addBook(1, 3);  // Book ID: 1, Category: 3
    myLibrary.addBook(2, 7);  // Book ID: 2, Category: 7
    myLibrary.addBook(3, 3);  // Book ID: 3, Category: 3
    myLibrary.addBook(4, 15); // Book ID: 4, Category: 15
    myLibrary.addBook(5, 3);  // Book ID: 5, Category: 3 (Warning should trigger here)
    myLibrary.addBook(6, 0);  // Book ID: 6, Category: 0

    // Display all books in the library
    cout << "\nAll books in the library:\n";
    myLibrary.displayAllBooks();

    // Display available books
    cout << "\nAvailable books in the library:\n";
    myLibrary.displayAvailableBooks();

    // Borrow a book by ID
    cout << "\nBorrowing Book ID 2:\n";
    if (myLibrary.borrowBook(2)) {
        cout << "Book ID 2 borrowed successfully.\n";
    }
    else {
        cout << "Failed to borrow Book ID 2.\n";
    }

    // Attempt to borrow the same book again
    cout << "\nAttempting to borrow Book ID 2 again:\n";
    if (myLibrary.borrowBook(2)) {
        cout << "Book ID 2 borrowed successfully.\n";
    }
    else {
        cout << "Failed to borrow Book ID 2.\n";
    }

    // Display borrowed books
    cout << "\nBorrowed books in the library:\n";
    myLibrary.displayBorrowedBooks();

    // Return a borrowed book by ID
    cout << "\nReturning Book ID 2:\n";
    if (myLibrary.returnBook(2)) {
        cout << "Book ID 2 returned successfully.\n";
    }
    else {
        cout << "Failed to return Book ID 2.\n";
    }

    // Display available books after returning
    cout << "\nAvailable books in the library after returning Book ID 2:\n";
    myLibrary.displayAvailableBooks();

    // Display the number of books in a specific category
    int categoryToCheck = 3;
    cout << "\nNumber of books in category " << categoryToCheck << ": " << myLibrary.countBooksInCategory(categoryToCheck) << endl;

    return 0;
}