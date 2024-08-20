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
		greeting = "Hello from class!";
	}

	void say_hello() {
		std::cout << greeting << "\n";
	}
};

#endif