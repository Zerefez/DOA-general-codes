#include <iostream>
using namespace std;


bool search(int A[], int N, int x) {
    // Base case: if the array is empty, return false
    if (N == 0) {
        return false;
    }

    // If the last element matches x, return true
    if (A[N - 1] == x) {
        return true;
    }

    // Recur for the rest of the array
    return search(A, N - 1, x);
}


void findMinMax(int A[], int N, int& minElement, int& maxElement) {
    // Base case: if this is the last element, initialize min and max
    if (N == 1) {
        minElement = maxElement = A[0];
        return;
    }

    // Recur for the rest of the array
    findMinMax(A, N - 1, minElement, maxElement);

    // Update min and max for the current element
    if (A[N - 1] < minElement) {
        minElement = A[N - 1];
    }
    if (A[N - 1] > maxElement) {
        maxElement = A[N - 1];
    }
}

int main() {
    int A[] = { 2, 8, 3, 5, 1, 7 };
    int N = sizeof(A) / sizeof(A[0]);
    int x = 5;

    // Searching for element x in the array
    bool found = search(A, N, x);

    if (found) {
        cout << x << " found in the array.\n";
    }
    else {
        cout << x << " not found in the array.\n";
    }

    // Finding the minimum and maximum elements in the array
    int minElement, maxElement;
    findMinMax(A, N, minElement, maxElement);

    cout << "Minimum element: " << minElement << "\n";
    cout << "Maximum element: " << maxElement << "\n";

    return 0;
}
