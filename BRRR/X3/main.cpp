

#include <iostream>
#include <chrono>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

void sum1( int n) {

	int sum = 0;
	for (int i = 0; i < n; ++i) { 
		++sum; 
	}
}

void sum2(int n) {

	int sum = 0;
	for (int i = 0; i < n; ++i) { 
		for (int j = 0; j < n; ++j) { 
			++sum; 
		} 
	}
}

void sum3(int n) {

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n * n; ++j) {
			++sum;
		}
	}
}
void sum4(int n) {

	int sum = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < i; ++j){ 
			++sum; 
		} 
	}
}

int main() {
	vector<int> testSizes = { 10, 100, 1000 };
	vector<double> times;
	vector<double> logN, logTime;

	for (int N : testSizes) {
		auto start = chrono::high_resolution_clock::now();
		//sum1(N);
		//sum2(N);
		//sum3(N);
		sum4(N);
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> duration = end - start;
		times.push_back(duration.count());
		logN.push_back(log(N));
		logTime.push_back(log(duration.count()));
		cout << "N = " << N << ", Time = " << duration.count() << " seconds" << endl;
	}


	cout << "\nSize vs Time:\n";
	cout << "N\tTime\n";
	for (size_t i = 0; i < testSizes.size(); ++i) {
		cout << testSizes[i] << "\t" << times[i] << endl;
	}

	double sumLogN = 0, sumLogTime = 0, sumLogNLogN = 0, sumLogN2 = 0;
	for (size_t i = 0; i < testSizes.size(); ++i) {
		sumLogN += logN[i];
		sumLogTime += logTime[i];
		sumLogNLogN += logN[i] * logTime[i];
		sumLogN2 += logN[i] * logN[i];
	}

	size_t n = testSizes.size();
	double denominator = n * sumLogN2 - sumLogN * sumLogN;
	double a = (sumLogN2 * sumLogTime - sumLogN * sumLogNLogN) / denominator;
	double b = (n * sumLogNLogN - sumLogN * sumLogTime) / denominator;

	cout << "\nEstimated Big-O Complexity: O(N^" << ceil(b) << ")\n";

	return 0;
}