
#include <iostream>
using namespace std;

void printTriangle(int m, int n) {
    // Base case: if m > n, stop the recursion
    if (m > n) {
        return;
    }

    // Print the current line with m '*' characters
    for (int i = 0; i < m; i++) {
        cout << '*';
    }
    cout << endl;

    // Recursive call to print the next line with m+1 '*' characters
    printTriangle(m + 1, n);

    // After the recursion completes, print the current line again (reverse pattern)
    for (int i = 0; i < m; i++) {
        cout << '*';
    }
    cout << endl;
}

int main() {
    int m = 4, n = 6;
    printTriangle(m, n);
    return 0;
}
