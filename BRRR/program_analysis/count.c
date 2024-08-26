#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int N;
    long count = 0;
    printf("input N: ");
    scanf("%d", &N);
    int msec = 0, trigger = 10; /* 10ms */
    clock_t before = clock();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                count++;
            }
        }
    }
    clock_t taken = clock() - before;
    msec = taken * 1000 / CLOCKS_PER_SEC;
    printf("count = %ld, msek taken = %d", count, msec);
}
