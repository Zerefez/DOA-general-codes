
#include <iostream>

using namespace std;

int oddSquare(int N) {
	if (N == 0) {
		return 0;
	}
	if (N % 2 != 0) {
		return N * N + oddSquare(N - 1);
	}
	else {
		return oddSquare(N - 1);
	}
}

int main(){
	cout << oddSquare(0) << endl;
	cout << oddSquare(4) << endl;
	cout << oddSquare(8) << endl;
	cout << oddSquare(7) << endl;
	return 0;
}
