using namespace std;

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <vector>

#include "point.h"
#include "pointimpl.h"

int main(int argc, char* argv[]) {
	int i, j, cnt = 0;
	srand(time(0));

	int N = 10;
	float d = 0.5;

	vector<PointImpl> array = vector<PointImpl>();

	for (int i = 0; i < N; i++) {
		array.push_back(PointImpl());
	}

	for (i = 0; i < N; i++) {
		for (j = i + 1; j < N; j++) {
			if (array[i].distance(array[j]) < d) {
				cnt++;
			}
		}
	}
	cout << cnt << " pairs within distance " << d << endl;
}

