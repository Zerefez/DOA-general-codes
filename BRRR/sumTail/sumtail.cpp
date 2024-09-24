#include <iostream>
#include "gtest/gtest.h"
using namespace std;

int sumTail(int* ar, int size, int sum)
{
	if (size == 0)
		return sum;

	return sumTail(ar + 1, size - 1, sum + ar[0]);
}

TEST(sumTail, sumTest)
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	ASSERT_EQ(sumTail(arr, 10, 0), 55);
}
