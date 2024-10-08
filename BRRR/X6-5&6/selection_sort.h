#pragma once	

#include <vector>
#include <functional>

using namespace std;

template <typename Comparable>
void selectionSort(vector<Comparable>& a) {
	for (int i = 0; i < a.size(); ++i) { // i is the index of the first unsorted element
		int minIndex = i;	             // index of the smallest element found
		for (int j = i + 1; j < a.size(); ++j) { // j is the index of the next element to be compared
			if (a[j] < a[minIndex]) { // if the next element is smaller than the current smallest element
				minIndex = j; // update the index of the smallest element
			}
		}
		swap(a[i], a[minIndex]); // swap the smallest element with the first unsorted element
	}
}
