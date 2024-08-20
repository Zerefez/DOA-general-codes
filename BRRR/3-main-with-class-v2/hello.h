#pragma once
#ifndef _HELLO_H_
#define _HELLO_H_

#include <string>
#include <iostream>


class Hello {
private:
	std::string greeting;

public:
	Hello() {
		greeting = "Hello from class v2!";
	};

	void say_hello(); // Note this prototype.
};

//#include "hello.cpp" // note the inclusion of the prototype implementations here.

#endif
