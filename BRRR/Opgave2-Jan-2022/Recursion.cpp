
#include <iostream>

using namespace std;

int sumDivisibleBy3(int N) {
	if (N == 0) {
		return 0;
	}
	if (N % 3 == 0) {
		return N + sumDivisibleBy3(N - 1);
	}
	return sumDivisibleBy3(N - 1);

}

int main() {
	cout << "Sum: " << sumDivisibleBy3(12) << endl;
	cout << "Sum: " << sumDivisibleBy3(14) << endl;
	return 0;
}