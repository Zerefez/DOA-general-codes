#include <iostream>
using namespace std;

void bookletPrint(int startPage, int endPage, int sheet = 1) {
    // Base case: If the starting page exceeds the ending page, stop the recursion
    if (startPage > endPage) {
        return;
    }

    // Front side of the current sheet: startPage (left), endPage (right)
    int leftFront = startPage;
    int rightFront = endPage;

    // Back side of the current sheet: startPage + 1 (left), endPage - 1 (right)
    int leftBack = startPage + 1;
    int rightBack = endPage - 1;

    // Output the pages for the current sheet
    cout << "Sheet " << sheet << " contains pages: ";
    cout << leftFront << ", " << leftBack << ", " << rightBack << ", " << rightFront << endl;

    // Recursively handle the next sheet with updated startPage and endPage
    bookletPrint(startPage + 2, endPage - 2, sheet + 1);
}

int main() {
    bookletPrint(1, 8);
    return 0;
}
