#include <iostream>
#include <vector>

using namespace std;

vector<int> countingSort(const vector<int>& input, int k) {
    int N = input.size();

    // Step 1: Initialize count array (k + 1 zeros) and output array
    vector<int> count(k + 1, 0);
    vector<int> output(N);

    // Step 2: Count occurrences of each value in input
    for (int i = 0; i < N; ++i) {
        int j = input[i];
        count[j] = count[j] + 1;
    }

    // Step 3: Accumulate counts to get final positions
    for (int i = 1; i <= k; ++i) {
        count[i] = count[i] + count[i - 1];
    }

    // Step 4: Build the output array by placing elements in correct positions
    for (int i = N - 1; i >= 0; --i) {
        int j = input[i];
        count[j] = count[j] - 1;
        output[count[j]] = input[i];
    }

    return output;
}

// Helper function to print a vector
void printArray(const vector<int>& A) {
    for (int i : A) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {

    int k = 45; // The maximum value in the input arra
    vector<int> input = { 24, 11, 23, 8, 6, 3, 1,3,45,0 };

    cout << "Original array: ";
    printArray(input);

    vector<int> sortedArray = countingSort(input, k);

    cout << "Sorted array: ";
    printArray(sortedArray);

    return 0;
}
