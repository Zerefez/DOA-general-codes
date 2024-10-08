#ifndef _INTRO_SORT_H_
#define _INTRO_SORT_H_

#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

using namespace std;

const int USE_INSERTION = 16; // Threshold for switching to insertion sort

template <typename Comparable>
void insertionSort(vector<Comparable>& a, int left, int right) {
	for (int i = left + 1; i <= right; ++i) { // Start from the second element
		Comparable tmp = a[i];               // Store the current element
		int j = i;						   // Start from the current index
		while (j > left && tmp < a[j - 1]) { // Move elements to the right
			a[j] = a[j - 1]; 			   // Shift to the right
			--j;						   // Move to the left
		}
		a[j] = tmp; 					   // Insert the stored element
	}
}

template <typename Comparable>
int* medianOfThree(vector<Comparable>& a, int left, int right) {
	int center = (left + right) / 2; // Calculate the center index

	if (a[center] < a[left])         // Sort the left and center elements
		swap(a[left], a[center]);    // Swap if the center is smaller
	if (a[right] < a[left])          // Sort the left and right elements
		swap(a[left], a[right]);    // Swap if the right is smaller
	if (a[right] < a[center])     // Sort the center and right elements
		swap(a[center], a[right]); // Swap if the right is smaller

	return &a[center];     // Return pointer to pivot (center element)
}

template <typename Comparable>
int partition(vector<Comparable>& a, int left, int right) {
	// Median-of-three pivot selection
	int* pivotPtr = medianOfThree(a, left, right); // Get the pivot pointer
	swap(*pivotPtr, a[right - 1]);   // Move pivot to the right
	Comparable pivot = a[right - 1]; // Store the pivot

	int i = left, j = right - 1; // Set the left and right pointers
	while (true) {              // Infinite loop
		while (a[++i] < pivot); // Move the left pointer
		while (pivot < a[--j]); // Move the right pointer
		if (i < j)			  // If pointers haven't crossed
			swap(a[i], a[j]); // Swap the elements
		else
			break;
	}

	swap(a[i], a[right - 1]); // Restore pivot
	return i;
}

template <typename Comparable>
void introsortUtil(vector<Comparable>& a, int left, int right, int depthLimit) {
	if (right - left + 1 <= USE_INSERTION) { // Check if array is small
		insertionSort(a, left, right);  // Switch to insertion sort for small arrays
		return;
	}

	if (depthLimit == 0) { // Check if recursion depth limit is reached

		make_heap(a.begin() + left, a.begin() + right + 1); // Convert to heap
		sort_heap(a.begin() + left, a.begin() + right + 1); // Sort the heap
		return;
	}

	if (right > left) { // Check if there are more than one element
		int pivotIndex = partition(a, left, right); // Partition the array
		introsortUtil(a, left, pivotIndex - 1, depthLimit - 1); // Sort left subarray
		introsortUtil(a, pivotIndex + 1, right, depthLimit - 1);// Sort right subarray
	}
}

template <typename Comparable>
void introSort(vector<Comparable>& a) {
	int depthLimit = 2 * log(a.size());  // Set the recursion depth limit
	introsortUtil(a, 0, a.size() - 1, depthLimit); // Call the utility function
}

#endif

