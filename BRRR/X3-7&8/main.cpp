#include "MinHeapPrioQueue.h"	
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    srand(static_cast<unsigned int>(time(nullptr)));
    MinHeapPrioQueue<int> queue;

    // Test 1: Insert random numbers and print queue
    cout << "Inserting random numbers into the queue:" << endl;
    for (int i = 0; i < 10; ++i) {
        int num = rand() % 100; // Random number between 0 and 99
        queue.push(num);
        cout << "Enqueued: " << num << ", ";
        queue.print();
    }

    // Test 2: Remove elements and print minimum after each removal
    cout << "\nRemoving elements from the queue:" << endl;
    while (!queue.empty()) {
        cout << "Current top: " << queue.top() << endl;
        queue.pop();
        queue.print();
    }

    // Test 3: Edge case - removing from an empty queue
    try {
        cout << "\nTrying to dequeue from an empty queue:" << endl;
        queue.pop(); // Should throw an exception
    }
    catch (const runtime_error& e) {
        cout << "Caught exception: " << e.what() << endl;
    }

    // Test 4: Enqueue duplicates
    cout << "\nEnqueuing duplicate values into the queue:" << endl;
    for (int i = 0; i < 5; ++i) {
        queue.push(10); // Enqueuing the same value
        cout << "Enqueued duplicate: 10, ";
        queue.print();
    }

    // Remove all elements to show the order
    cout << "\nRemoving duplicates from the queue:" << endl;
    while (!queue.empty()) {
        cout << "Current top: " << queue.top() << endl;
        queue.pop();
        queue.print();
    }

    // Test 5: Enqueue in sorted order (ascending)
    cout << "\nEnqueuing numbers in ascending order:" << endl;
    for (int i = 1; i <= 10; ++i) {
        queue.push(i);
        cout << "Enqueued: " << i << ", ";
        queue.print();
    }

    // Remove all elements again
    cout << "\nRemoving elements from the ascending order queue:" << endl;
    while (!queue.empty()) {
        cout << "Current top: " << queue.top() << endl;
        queue.pop();
        queue.print();
    }

    // Test 6: Enqueue in sorted order (descending)
    cout << "\nEnqueuing numbers in descending order:" << endl;
    for (int i = 10; i >= 1; --i) {
        queue.push(i);
        cout << "Enqueued: " << i << ", ";
        queue.print();
    }

    // Final removal
    cout << "\nRemoving elements from the descending order queue:" << endl;
    while (!queue.empty()) {
        cout << "Current top: " << queue.top() << endl;
        queue.pop();
        queue.print();
    }

    return 0;
}
