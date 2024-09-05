#include <iostream>
#include <assert.h>
using namespace std;

class X {
public:
	int a, b, i, j;
	const int& r;
	int* p;

	X(int i)
		: r(a) 	// initializes X::r to refer to X::a. Kind of like an "alias". 
		// Every access to X::r is implicitly 
		// de-referencing the pointer to get to the value of a.
		, p(&a) // initializes X::p to refer to X::p. Almost equivalent to X::r
		// except now we have to de-reference p explicitly, and it is not const.
		, b{ i } 	// initializes X::b to the value of the parameter i, using the default constructor. 
		// Read more in https://www.modernescpp.com/index.php/initialization
		, i(i) 	// initializes X::i to the value of the parameter i
		, j(this->i) // initializes X::j to the value of X::i
		, a{ i } 	// initializes X::a to the value of i
	{ }
};

class Y {
public:
	int a, b, i, j;
	const int& r = a;  // equivalent to r(a) initializer in X
	int* p;

	Y(int i)
	{ // The following are equivalent to the respective initializer in X
		p = &a;
		b = i;
		this->i = i;
		j = this->i;
		a = i;
	}
};

int main(int argc, char* argv[]) {
	X someX(10);
	X* anotherX = new X(5);

	assert(someX.a == 10 && anotherX->a == 5);
	assert(someX.b == 10 && anotherX->b == 5);
	assert(someX.i == 10 && anotherX->i == 5);
	assert(someX.j == 10 && anotherX->j == 5);
	assert(someX.r == 10 && anotherX->r == 5);
	assert((*someX.p) == 10 && (*anotherX->p) == 5);

	Y someY{ 20 };
	assert(someY.a == 20);
	assert(someY.b == 20);
	assert(someY.i == 20);
	assert(someY.j == 20);
	assert(someY.r == 20);
	assert((*someY.p) == 20);

	delete anotherX;
}
