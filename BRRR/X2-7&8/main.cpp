#include <iostream>
#include <cstdlib>
#include <ctime>
#include "min_heap.h"

using namespace std;

int main() {

    srand(static_cast<unsigned int>(time(nullptr)));
    MinHeap<int> heap;

    // Test 1: Insert random numbers and print heap
    cout << "Inserting random numbers into the heap:" << endl;
    for (int i = 0; i < 10; ++i) {
        int num = rand() % 100; // Random number between 0 and 99
        heap.insert(num);
        cout << "Inserted: " << num << ", ";
        heap.printHeap();
    }

    // Test 2: Remove elements and print minimum after each removal
    cout << "\nRemoving elements from the heap:" << endl;
    while (!heap.isEmpty()) {
        cout << "Current minimum: " << heap.peek() << endl;
        heap.remove();
        heap.printHeap();
    }

    // Test 3: Edge case - removing from an empty heap
    try {
        cout << "\nTrying to remove from an empty heap:" << endl;
        heap.remove(); // Should throw an exception
    }
    catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    // Test 4: Insert duplicates
    cout << "\nInserting duplicate values into the heap:" << endl;
    for (int i = 0; i < 5; ++i) {
        heap.insert(10); // Inserting the same value
        cout << "Inserted duplicate: 10, ";
        heap.printHeap();
    }

    // Remove all elements to show the order
    cout << "\nRemoving duplicates from the heap:" << endl;
    while (!heap.isEmpty()) {
        cout << "Current minimum: " << heap.peek() << endl;
        heap.remove();
        heap.printHeap();
    }

    // Test 5: Insert in sorted order (ascending)
    cout << "\nInserting numbers in ascending order:" << endl;
    for (int i = 1; i <= 10; ++i) {
        heap.insert(i);
        cout << "Inserted: " << i << ", ";
        heap.printHeap();
    }

    // Remove all elements again
    cout << "\nRemoving elements from the ascending order heap:" << endl;
    while (!heap.isEmpty()) {
        cout << "Current minimum: " << heap.peek() << endl;
        heap.remove();
        heap.printHeap();
    }

    // Test 6: Insert in sorted order (descending)
    cout << "\nInserting numbers in descending order:" << endl;
    for (int i = 10; i >= 1; --i) {
        heap.insert(i);
        cout << "Inserted: " << i << ", ";
        heap.printHeap();
    }

    // Final removal
    cout << "\nRemoving elements from the descending order heap:" << endl;
    while (!heap.isEmpty()) {
        cout << "Current minimum: " << heap.peek() << endl;
        heap.remove();
        heap.printHeap();
    }

    return 0;
}
