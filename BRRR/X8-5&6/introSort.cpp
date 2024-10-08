#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib> 
#include "intro_sort.h" 

using namespace std;
using namespace std::chrono;

// Function to generate random input data
vector<int> generateRandomVector(int size) {
    vector<int> result(size);
    for (int i = 0; i < size; ++i) {
        result[i] = rand() % 1000000;  // Generate random numbers up to 1 million
    }
    return result;
}

// Function to print the contents of a vector
void printVector(const vector<int>& v) {
    for (int num : v) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Test with different input sizes
    vector<int> sizes = { 10,100 };  // Reduced sizes for readability in output

    // Test for different values of USE_INSERTION
    const int insertionSizes[] = { 8, 16,24 };  // Reduced values for simplicity

    for (int insertionSize : insertionSizes) {
        cout << "Testing with USE_INSERTION = " << insertionSize << endl;
        for (int size : sizes) {
            vector<int> testArray = generateRandomVector(size);

            // Show the vector before sorting
            cout << "Before sorting (size " << size << "):" << endl;
            printVector(testArray);

            // Measure start time
            auto start = high_resolution_clock::now();

            // Sort the array using introSort
            introSort(testArray);

            // Measure end time
            auto end = high_resolution_clock::now();

            // Show the vector after sorting
            cout << "After sorting:" << endl;
            printVector(testArray);

            // Calculate the duration in microseconds
            auto duration = duration_cast<microseconds>(end - start).count();

            // Output the time taken
            cout << "Time taken: " << duration << " microseconds" << endl;
            cout << "----------------------------------------" << endl;
        }
    }

    return 0;
}
