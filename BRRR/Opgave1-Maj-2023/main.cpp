

#include <iostream>

using namespace std;

int main()
{
	int height = 0, line = 1, star = 0, spaces = 0;
	cout << "input a posetive number" << endl;
	cin >> height;
	if (height < 0) {
		cout << "you number was negative, try again" << endl;
		return 0;
	}
	while (height >= line) {
		spaces = 0;
		while (spaces < height - line) { 
			cout << " ";
			spaces++;
		}
		star = 0;
		while ((line * 2 - 1) > star) { 
			cout << "*";
			star++;
		}
		line++;
		cout << endl;
	}
	return 0;
}