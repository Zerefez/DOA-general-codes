#include <iostream>
#include "gtest/gtest.h"

int sum(int* ar, int size)
{
	int temp = 0;

	if (size == 0)
		return 0;

	temp = ar[0] + sum(ar + 1, size - 1);
	return temp;
}

/* int sum(int *ar, int size) */
/* { */
/* 	if (size == 0) */
/* 		return 0; */

/* 	return ar[0] + sum(ar + 1, size - 1); */
/* } */

TEST(sum, sumTest)
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	ASSERT_EQ(sum(arr, 10), 55);
}

