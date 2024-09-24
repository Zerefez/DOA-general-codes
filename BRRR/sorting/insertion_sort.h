#ifndef _INSERTION_SORT_H_
#define _INSERTION_SORT_H_
#include <vector>
#include <functional>

using namespace std;

/**
 * Simple insertion sort.
 */
template <typename Comparable>
void insertionSort(vector<Comparable>& a) {
	for (int p = 1; p < a.size(); ++p) {
		Comparable tmp = std::move(a[p]);

		int j;
		for (j = p; j > 0 && tmp < a[j - 1]; --j) {
			a[j] = std::move(a[j - 1]);
		}
		a[j] = std::move(tmp);
	}
}

/*
 * This is the more public version of insertion sort.
 * It requires a pair of iterators and a comparison
 * function object.
 */
template <typename Iterator, typename Comparator>
void insertionSort(const Iterator& begin, const Iterator& end, Comparator less) {
	if (begin == end)
		return;

	for (Iterator j, p = begin + 1; p != end; ++p) {
		auto tmp = std::move(*p);
		for (j = p; j != begin && less(tmp, *(j - 1)); --j)
			*j = std::move(*(j - 1));
		*j = std::move(tmp);
	}
}

/*
 * The two-parameter version calls the three parameter version, using C++11.
 */
template <typename Iterator >
void insertionSort(const Iterator& begin, const Iterator& end) {
	insertionSort(begin, end, less<decltype(*begin)> { });
}

#endif
