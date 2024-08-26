#include <stdio.h>
#include <time.h>
#include <math.h>

int myMethod(int N)
{
	int x = 0;
	for (int i = 1; i <= sqrt(N); i++)
	{
		for (int j = 1; j <= N; j++)
			for (int k = 1; k < N;) {
				x++;
				k = k * 2;
			}
	}
	return x;
}

int main(void) {
	int N, msec = 0;
	printf("Input N:");
	scanf_s("%d", &N);
	clock_t before = clock();
	myMethod(N);
	clock_t duration = clock() - before;
	msec = duration * 1000 / CLOCKS_PER_SEC;
	printf("duration in msec: %d", msec);
	return 0;
}
