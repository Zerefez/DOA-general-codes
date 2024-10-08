#include <algorithm>
#include <iostream>
#include <vector>
#include <chrono>  
#include <cassert>
#include "intro_sort.h"

using namespace std;
using namespace std::chrono;

// Function to display the vector
template<class T>
void show(const vector<T>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i < v.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;
}


int main() {
    vector<int> input = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };

    // Measuring time for IntroSort
    vector<int> introArray = input;  // Copy for sorting
    cout << "IntroSort:" << endl;
    cout << "Before sorting: ";
    show(introArray);

    auto start = high_resolution_clock::now();
    introSort(introArray);
    auto end = high_resolution_clock::now();

    cout << "After sorting: ";
    show(introArray);
    auto durationIntro = duration_cast<microseconds>(end - start).count();
    cout << "Time taken by IntroSort: " << durationIntro << " microseconds" << endl;
    cout << "----------------------------------------" << endl;

    // Measuring time for STL Sort
    vector<int> stlArray = input;  // Copy for sorting
    cout << "STL Sort:" << endl;
    cout << "Before sorting: ";
    show(stlArray);

    start = high_resolution_clock::now();
    sort(stlArray.begin(), stlArray.end());
    end = high_resolution_clock::now();

    cout << "After sorting: ";
    show(stlArray);
    auto durationSTL = duration_cast<microseconds>(end - start).count();
    cout << "Time taken by STL Sort: " << durationSTL << " microseconds" << endl;

    return 0;
}
