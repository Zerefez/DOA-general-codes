#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <functional>
#include <limits>

// Function to test

/*
 static int myMethod(int N) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N * std::sqrt(N); k++) {
                x++;
            }
            j *= 2; // This line reduces the iterations of the inner loop
        }
        y = i;
    }
    for (int i = 0; i < N * N; i++) {
        y++;
    }
    return x + y;
}
*/

int func2(int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        res = res + 1;
    }
    return res;
}

int func1(int n) {
    int x = 0;
    for (int i = 0; i < n; i++) {
        x = x + func2(n);
    }
    return x;
}


// Helper function to measure execution time
template <typename Func>
double measureTime(Func func, int n) {
    auto start = std::chrono::high_resolution_clock::now();
    func(n);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(end - start).count();
}

// Logarithmic fitting function for time complexities
std::string fitLogScale(const std::vector<int>& sizes, const std::vector<double>& times) {
    double sumLogX = 0, sumLogY = 0, sumLogXLogY = 0, sumLogX2 = 0;
    int n = sizes.size();

    // Logarithmic fitting using the form y = a * x^b or log(y) = b * log(x) + log(a)
    for (int i = 0; i < n; ++i) {
        double logX = std::log2(sizes[i]);
        double logY = std::log2(times[i]);
        sumLogX += logX;
        sumLogY += logY;
        sumLogXLogY += logX * logY;
        sumLogX2 += logX * logX;
    }

    // Calculating b and log(a) for the best fit line
    double b = (n * sumLogXLogY - sumLogX * sumLogY) / (n * sumLogX2 - sumLogX * sumLogX);
    double logA = (sumLogY - b * sumLogX) / n;

    // Convert log(a) to a
    double a = std::pow(2, logA);

    // Detect specific complexities based on 'b' values
    if (b >= 0.9 && b <= 1.1) {
        return "O(1)";
    }
    else if (b >= 1.4 && b <= 1.6) {
        return "O(log N)";
    }
    else if (b >= 1.9 && b <= 2.1) {
        return "O(N)";
    }
    else if (b >= 2.4 && b <= 2.6) {
        return "O(N log N)";
    }
    else if (b >= 2.8 && b <= 3.2) {
        return "O(N^2)";
    }
    else if (b >= 3.5 && b <= 4.0) {
        return "O(N^3)";
    }
    else if (b >= 4.2 && b <= 4.8) {
        return "O(N^2 * sqrt(N))";
    }
    else if (b >= 5.5 && b <= 6.5) {
        return "O(2^N)";  // Exponential growth
    }
    else if (b >= 10.0) {
        return "O(N!)";  // Factorial growth
    }
    else {
        return "O(unknown)";
    }
}

int main() {
    // Input sizes for testing
    std::vector<int> inputSizes = { 100, 200, 300 };
    std::vector<double> times;

    // Measure execution times
    for (int size : inputSizes) {
        double timeTaken = measureTime(func1, size);
        times.push_back(timeTaken);
        std::cout << "Input Size: " << size
            << ", Time: " << std::fixed << std::setprecision(6) << timeTaken << " seconds\n";
    }

    // Fit time complexity based on log-log fit
    std::string estimatedComplexity = fitLogScale(inputSizes, times);
    std::cout << "Estimated Time Complexity: " << estimatedComplexity << "\n";

    return 0;
}
