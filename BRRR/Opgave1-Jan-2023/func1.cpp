

#include <iostream>

using namespace std;

int func1(int n) {
    int x = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < log(n); j++) {
            x = x + j;
        }
    }
    return x;
}

int main() {
	cout << func1(8) << endl;
	return 0;
}