#pragma once
#ifndef _LINEAR_SEARCH_H_
#define _LINEAR_SEARCH_H_

using namespace std;

/**
 * Performs the standard linear search using one comparison per item.
*/
template <typename iterator, typename Object>
iterator linearSearch(iterator first, iterator last, const Object& value) {
	iterator begin = first;
	iterator end = last;
	while (begin != end) {
		if (*begin == value) {
			return begin;
		}
		else {
			begin = std::next(begin);
		}
	}
	return end;
}

#endif