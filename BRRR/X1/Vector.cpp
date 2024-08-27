#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
    // Initialize random seed
    srand((0));

    int M, N;
    cout << "Enter the number of elements in the first vector (M): ";
    cin >> M;
    cout << "Enter the number of random integers to check (N): ";
    cin >> N;

    cout << endl;

    // Generate M random integers in the range [0, 99] and store them in a vector
    vector<int> vecM;

    cout << "Vector M: ";
    for (int i = 0; i < M; ++i) {
        int randomNum = rand() % 100;
        vecM.push_back(randomNum);
        cout << randomNum << " ";
    }
    cout << endl<<endl;

    // Generate N random integers in the same range and store them in a vector
    vector<int> vecN;
    vector<int> matchedNumbers;
    cout << "Vector N: ";
    for (int i = 0; i < N; ++i) {
        int randomNum = rand() % 100;
        vecN.push_back(randomNum);
        cout << randomNum << " ";

        // Check if the random number is in vecM and store matches
        vector<int>::iterator it = find(vecM.begin(), vecM.end(), randomNum);
         if(it != vecM.end()) {
            matchedNumbers.push_back(randomNum);
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
