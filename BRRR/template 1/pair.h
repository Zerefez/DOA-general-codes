#pragma once
#ifndef _Pair_H_
#define _Pair_H_

#include <iostream>

template <typename T1, typename T2>
class Pair {
private:
	T1 first;
	T2 second;

public:
	Pair(T1 f, T2 s) {
		first = f;
		second = s;
	}

	void print() {
		std::cout << first << " " << second << std::endl;
	}
};

#endif
