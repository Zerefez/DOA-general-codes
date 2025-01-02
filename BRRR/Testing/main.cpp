
#include <iostream>	

using namespace std;

int theMaximumAchievableX(int num, int t) {
	int x = 0;
	for (int i = 1; i <= num; i++) {
		x += i;
		if (x > t) {
			return i - 1;
		}
	}
	return num;

}

int main() {
	int num, t;
	cin >> num >> t;
	cout << theMaximumAchievableX(num, t) << endl;
	return 0;
}