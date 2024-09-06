#include <stdio.h>
#include <time.h>
#include <iostream>
#include "StopwatchGeneric.h"

int f(int x)
{
    if (x == 0)
        return 0;
    else
        return x + f(x - 1);
}

int g(int x)
{
    return (x * (x + 1)) / 2;
}

int main()
{
    unsigned int i;
    int res, start, clicks;
    Stopwatch t;

    while (true) {
        std::cin >> i;
        start = clock(); t.start(); res = g(i); clicks = clock() - start; t.stop();
        printf("g(%d)=%d\t%dticks\t%luus\n", i, res, clicks, t.getDuration());
        start = clock(); t.start(); res = f(i); clicks = clock() - start; t.stop();
        printf("f(%d)=%d\t%dticks\t%luus\n", i, res, clicks, t.getDuration());
    }
}
