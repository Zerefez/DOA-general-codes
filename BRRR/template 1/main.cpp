#include "pair.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    Pair<std::string, int> myDog("Dog", 36);
    Pair<double, double> myFloats(3.0, 2.18);

	myDog.print();
}

// Compile with: cl /EHsc .\main.cpp
