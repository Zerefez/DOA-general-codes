using namespace std;

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <vector>

#include "point_plus.h"

int main(int argc, char* argv[]) {
	int i, j, cnt = 0 , equ = 0;

	if (argc != 3) {
		cout << "Usage: test_point_plus n d" << endl;
		return -1;
	}
	srand(time(0));

	int N = atoi(argv[1]);
	float d = atof(argv[2]);

	vector<Point> array = vector<Point>();

	for (int i = 0; i < N; i++) {
		array.push_back(Point());
	}

	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			if (array[i] == array[j]) {
				equ++;
			}
			if (Point::distance(array[i], array[j]) < d) {
				cnt++;
			}
		}
	}

	cout << cnt << " pairs within distance " << d << endl;
	cout << equ << " pairs of equal points " << endl;
}
