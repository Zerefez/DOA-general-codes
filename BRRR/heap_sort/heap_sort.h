#pragma once
#ifndef _HEAP_SORT_H_
#define _HEAP_SORT_H_

/**
 * Internal method for heapsort that is used in
 * deleteMax and buildHeap.
 * i is the position from which to percolate down.
 * n is the logical size of the binary heap.
 */
template <typename Comparable>
void minHeapify(vector<Comparable>& array, int node, int n) {
	int child;
	Comparable tmp = std::move(array[node]);

	for (; node * 2 + 1 < n; node = child) {
		child = node * 2 + 1;
		if (child != n - 1 && array[child + 1] < array[child])
			++child;
		if (array[child] < tmp)
			array[node] = std::move(array[child]);
		else
			break;
	}
	array[node] = std::move(tmp);
}

/**
 * Standard heapsort.
 */
template <typename Comparable>
void heapSort(vector<Comparable>& array) {
	for (int i = array.size() / 2 - 1; i >= 0; --i)	/* buildHeap */
		minHeapify(array, i, array.size());

	for (int j = array.size() - 1; j > 0; --j) {
		std::swap(array[0], array[j]);	/* deleteMin */
		minHeapify(array, 0, j);
	}
	std::reverse(array.begin(), array.end());
}

#endif
