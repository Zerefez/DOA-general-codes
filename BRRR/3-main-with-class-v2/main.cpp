#include "hello.h"

int main()
{
    Hello h = Hello();
    h.say_hello();
    return 0;
}

// Compile with: cl /EHsc .\main.cpp
