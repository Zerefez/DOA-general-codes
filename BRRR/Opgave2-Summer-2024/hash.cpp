#include <iostream>
#include <string>

using namespace std;


unsigned long long hashString(const std::string& str) {
    unsigned long long hash = 5381; // Use 64-bit integer
    for (char c : str) {
        hash = (hash * 33) + c; // Compute hash
        cout << c << " -> Intermediate Hash: " << hash << endl; // Print each step
    }
    return hash;
}

int main() {
    cout << "go Hash: " << hashString("go") << endl;
    cout << "ben Hash: " << hashString("ben") << endl;
    cout << "Adam Hash: " << hashString("adam") << endl;
    return 0;
}
