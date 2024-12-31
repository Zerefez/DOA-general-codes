#include <iostream>
#include <vector>
#include <chrono>
#include <functional>
#include <cmath>

// Function to estimate time complexity by timing a user-provided function
void estimateTimeComplexity(const std::function<void(int)>& func, int maxInputSize) {
    std::vector<int> inputSizes;
    std::vector<double> runtimes;

    // Generate input sizes (e.g., 1, 10, 100, ..., up to maxInputSize)
    for (int i = 1; i <= maxInputSize; i *= 10) {
        inputSizes.push_back(i);
    }

    // Measure the runtime for each input size
    for (int size : inputSizes) {
        auto start = std::chrono::high_resolution_clock::now();
        func(size);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsed = end - start;
        runtimes.push_back(elapsed.count());

        std::cout << "Input size: " << size << ", Runtime: " << elapsed.count() << " seconds" << std::endl;
    }

    // Analyze runtime trends
    std::cout << "\nAnalyzing time complexity based on runtime trends...\n";

    for (size_t i = 1; i < inputSizes.size(); ++i) {
        double growthFactor = runtimes[i] / runtimes[i - 1];
        double inputGrowth = static_cast<double>(inputSizes[i]) / inputSizes[i - 1];
        double complexityFactor = log(growthFactor) / log(inputGrowth);

        std::cout << "Between input sizes " << inputSizes[i - 1] << " and " << inputSizes[i]
            << ", estimated complexity: O(n^" << complexityFactor << ")" << std::endl;
    }
}

// Example function to analyze
void exampleFunction(int n) {
    // Simulated work: O(n^2) example
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            // Simulate some work
        }
    }
}

int main() {
    std::cout << "Time Complexity Estimator\n";

    // Call the estimation function with the example function and a maximum input size
    estimateTimeComplexity(exampleFunction, 1000);

    return 0;
}
