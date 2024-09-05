#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Function to measure
int myMethod(int N) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N * sqrt(N); k++) {
                x++;
            }
        }
    }
    for (int i = 0; i < N * N; i++) {
        y++;
    }
    return x + y;
}

// Function to measure execution time and estimate Big-O complexity
void analyzeComplexity() {
    vector<int> testSizes = { 10, 20, 30, 40, 50 }; // Add more sizes if needed
    vector<double> times;
    vector<double> logN, logTime;

    for (int N : testSizes) {
        auto start = chrono::high_resolution_clock::now();
        myMethod(N);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;
        times.push_back(duration.count());
        logN.push_back(log(N));
        logTime.push_back(log(duration.count()));
        cout << "N = " << N << ", Time = " << duration.count() << " seconds" << endl;
    }

    // Output times for analysis
    cout << "\nSize vs Time:\n";
    cout << "N\tTime\n";
    for (size_t i = 0; i < testSizes.size(); ++i) {
        cout << testSizes[i] << "\t" << times[i] << endl;
    }

    // Estimate Big-O Complexity using Linear Regression
    double sumLogN = 0, sumLogTime = 0, sumLogNLogN = 0, sumLogN2 = 0;
    for (size_t i = 0; i < testSizes.size(); ++i) {
        sumLogN += logN[i];
        sumLogTime += logTime[i];
        sumLogNLogN += logN[i] * logTime[i];
        sumLogN2 += logN[i] * logN[i];
    }

    size_t n = testSizes.size();
    double denominator = n * sumLogN2 - sumLogN * sumLogN;
    if (denominator == 0) {
        cout << "Cannot compute the exponent due to zero denominator." << endl;
        return;
    }

    double exponent = (n * sumLogNLogN - sumLogN * sumLogTime) / denominator;

    cout << fixed << setprecision(2);
    cout << "Estimated Big-O Complexity: O(N^" << exponent << ")" << endl;
}

int main() {
    analyzeComplexity();
    return 0;
}
