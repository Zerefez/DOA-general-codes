
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
vector<T> partitionEvenOdd(vector<T>& arg) {
	int hi = arg.size() - 1;
	int lo = 0;
	
	while(hi>=lo){
		if (arg[lo] % 2 == 0) {
			if (arg[hi] % 2 != 0) {
				swap(arg[lo], arg[hi]);
				lo++;
				hi--;
			}
			else {
				hi--;
			}
		}
		else {
			lo++;
		}
	}
	return arg;
}

int main() {
	vector<int> arg = { 7, 2, 9, 4, 6, 1, 3, 8, 5 };
	vector<int> result = partitionEvenOdd(arg);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	cout << endl;
	
	return 0;
}