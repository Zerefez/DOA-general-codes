#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    // Initialize random seed
    srand(0);

    int M, N;
    cout << "Enter the number of elements in the first vector (M): ";
    cin >> M;
    cout << "Enter the number of random integers to check (N): ";
    cin >> N;

    cout << endl;

    vector<int> vecM;
    vector<int> vecN;
    vector<int> matchedNumbers;

	// Generate random numbers for vectors M and N
    cout << "Vector M: ";
    for (int i = 0; i < M; ++i) {
        int randomNumM = rand() % 100;
        vecM.push_back(randomNumM);
        cout << randomNumM << " ";
    }
    cout << endl;

    cout << "Vector N: ";
    for (int i = 0; i < N; ++i) {
        int randomNumN = rand() % 100;
        vecN.push_back(randomNumN);
        cout << randomNumN << " ";

        // Manually check if randomNumN is in vecM
        for (int j = 0; j < vecM.size(); ++j) {
            if (vecM[j] == randomNumN) {
                matchedNumbers.push_back(randomNumN);
                break;  
            }
        }
    }
    cout << endl << endl;

    // Output the result
    cout << "Number of random integers found in the vector: " << matchedNumbers.size() << endl << endl;

    // Print the matched numbers
    if (!matchedNumbers.empty()) {
        cout << "Matched numbers: ";
        for (int num : matchedNumbers) {
            cout << num << " ";
        }
        cout << endl << endl;
    }
    else {
        cout << "No numbers from Vector N were found in Vector M." << endl;
    }

    return 0;
}
