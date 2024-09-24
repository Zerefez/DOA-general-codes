#include <iostream>
#include <assert.h>

using namespace std;

int sum(int* ar, int size)
{
	if (size == 0)
		return 0;

	int toSum = ar[0];
	int partialTotal = sum(ar + 1, size - 1);
	return toSum + partialTotal;
}

int main() {
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	assert(sum(arr, 10) == 55);

	return 0;
}
