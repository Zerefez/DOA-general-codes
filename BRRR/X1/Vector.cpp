#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    // Initialize random seed
    srand(time(0));

    int M, N;
    cout << "Enter the number of elements in the first vector (M): ";
    cin >> M;
    cout << "Enter the number of random integers to check (N): ";
    cin >> N;

    // Generate M random integers in the range [0, 9] and store them in a vector
    vector<int> vecM;
    cout << "Vector M: ";
    for (int i = 0; i < M; ++i) {
        int randomNum = rand() % 100;
        vecM.push_back(randomNum);
        cout << randomNum << " ";
    }
    cout << endl;

    // Generate N random integers in the same range and count how many are in vecM
    int count = 0;
    cout << "Vector N: ";
    for (int i = 0; i < N; ++i) {
        int randomNum = rand() % 100;
        cout << randomNum << " ";

        // Use an iterator to check if the random number is in vecM
        if (find(vecM.begin(), vecM.end(), randomNum) != vecM.end()) {
            ++count;
        }
    }
    cout << endl;

    // Output the result
    cout << "Number of random integers found in the vector: " << count << endl;

    return 0;
}