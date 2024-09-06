#include <iostream>
#include <stdio.h>

int f(int x)
{
    if (x == 0)
        return 0;
    else
        return x + f(x - 1);
}

int main()
{
    unsigned int i;

    while (true) {
        std::cin >> i;
        printf("f(%d)=%d\n", i, f(i));
    }
}
