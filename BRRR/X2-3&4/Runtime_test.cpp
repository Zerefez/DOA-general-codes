#include "Stack.h"
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

void test_push_pop(int N) {
    Stack<int> stack;

    cout << "Testing for " << N << " elements." << endl;

    // Measure the time taken for push operations
    auto start_push = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        stack.push(i);
    }
    auto end_push = high_resolution_clock::now();
    auto duration_push = duration_cast<microseconds>(end_push - start_push).count();
    cout << "Time taken for " << N << " push operations: " << duration_push << " microseconds." << endl;

    // Measure the time taken for pop operations
    auto start_pop = high_resolution_clock::now();
    for (int i = 0; i < N; i++) {
        stack.pop();
    }
    auto end_pop = high_resolution_clock::now();
    auto duration_pop = duration_cast<microseconds>(end_pop - start_pop).count();
    cout << "Time taken for " << N << " pop operations: " << duration_pop << " microseconds." << endl;

    cout << "---------------------------------" << endl;
}

int main() {
    // Test for different N values
    //test_push_pop(100);
    test_push_pop(1000);
    //test_push_pop(10000);

    return 0;
}
