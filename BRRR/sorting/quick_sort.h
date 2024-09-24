#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

/**
 * Order left, center, and right and hide the pivot.
 * Then compute partition, restore the pivot and return its position.
 */
#include <vector>
using namespace std;

template <typename Comparable>
int partition(vector<Comparable>& a, int left, int right) {
	int center = (left + right) / 2;

	if (a[center] < a[left])
		std::swap(a[left], a[center]);
	if (a[right] < a[left])
		std::swap(a[left], a[right]);
	if (a[right] < a[center])
		std::swap(a[center], a[right]);

	// Place pivot at position right - 1
	std::swap(a[center], a[right - 1]);

	// Now the partitioning
	Comparable& pivot = a[right - 1];
	int i = left, j = right - 1;
	do {
		while (a[++i] < pivot);
		while (pivot < a[--j]);
		if (i < j) {
			std::swap(a[i], a[j]);
		}
	} while (i < j);

	std::swap(a[i], a[right - 1]);	// Restore pivot
	return i;
}

/**
 * Internal quicksort method that makes recursive calls.
 * a is an array of Comparable items.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void quickSort(vector<Comparable>& a, int left, int right) {
	if (right - left > 1) {
		int i = partition(a, left, right);
		quickSort(a, left, i - 1);	// Sort small elements
		quickSort(a, i + 1, right);	// Sort large elements
	}
	else {						// Do an insertion sort on the subarray
		if (a[left] > a[right]) {
			std::swap(a[left], a[right]);
		}
	}
}

/**
 * Quicksort algorithm (driver).
 */
template <typename Comparable> void quickSort(vector < Comparable >& a) {
	quickSort(a, 0, a.size() - 1);
}

#endif

