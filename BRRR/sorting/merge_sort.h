#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

/**
 * Internal method that merges two sorted halves of a subarray.
 * a is an array of Comparable items.
 * tmp is an array to place the merged result.
 * leftPos is the left-most index of the subarray.
 * rightPos is the index of the start of the second half.
 * rightEnd is the right-most index of the subarray.
 */
template <typename Comparable>
void merge(vector<Comparable>& a, vector<Comparable>& tmp,
	int leftPos, int rightPos, int rightEnd) {
	int leftEnd = rightPos - 1;
	int pos = leftPos;
	int numElements = rightEnd - leftPos + 1;

	// Main loop
	while (leftPos <= leftEnd && rightPos <= rightEnd) {
		if (a[leftPos] <= a[rightPos]) {
			tmp[pos++] = std::move(a[leftPos++]);
		}
		else {
			tmp[pos++] = std::move(a[rightPos++]);
		}
	}

	while (leftPos <= leftEnd) {    // Copy rest of first half
		tmp[pos++] = std::move(a[leftPos++]);
	}

	while (rightPos <= rightEnd) {	// Copy rest of right half
		tmp[pos++] = std::move(a[rightPos++]);
	}

	// Copy tmp back
	for (int i = 0; i < numElements; ++i, --rightEnd) {
		a[rightEnd] = std::move(tmp[rightEnd]);
	}
}

/**
 * Internal method that makes recursive calls.
 * a is an array of Comparable items.
 * tmp is an array to place the merged result.
 * left is the left-most index of the subarray.
 * right is the right-most index of the subarray.
 */
template <typename Comparable>
void mergeSort(vector<Comparable>& a, vector<Comparable>& tmp,
	int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		mergeSort(a, tmp, left, center);
		mergeSort(a, tmp, center + 1, right);
		merge(a, tmp, left, center + 1, right);
	}
}

/**
 * Mergesort algorithm (external).
 */
template <typename Comparable>
void mergeSort(vector<Comparable>& a) {
	vector<Comparable> tmp(a.size());
	mergeSort(a, tmp, 0, a.size() - 1);
}

#endif

