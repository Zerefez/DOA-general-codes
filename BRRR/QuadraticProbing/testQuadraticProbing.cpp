#include <iostream>
#include <assert.h>
#include "QuadraticProbing.h"
using namespace std;

// Simple main
int main()
{
    HashTable<int> h1;
    HashTable<int> h2;

    const int NUMS = 4000;
    const int GAP = 37;
    int i;

    cout << "Checking... (no more output means success)" << endl;

    for (i = GAP; i != 0; i = (i + GAP) % NUMS)
        h1.insert(i);

    h2 = h1;

    for (i = 1; i < NUMS; i += 2)
        h2.remove(i);

    for (i = 2; i < NUMS; i += 2)
        if (!h2.contains(i))
            cout << "Contains fails " << i << endl;

    for (i = 1; i < NUMS; i += 2)
    {
        if (h2.contains(i))
            cout << "OOPS!!! " << i << endl;
    }

    HashTable<int> h3 = HashTable<int>(7);

    assert(h3.size() == 0);

    h3.insert(1); // should end up in position x.

    assert(h3.size() == 1);

    static hash<int> hf;

    size_t hf_1 = hf(1);
    cout << "hf_1=" << hf_1 << endl;

    h3.remove(1); // should mark position x as deleted.

    assert(h3.size() == 1); // This is normal, as we did not really delete the element. It was just marked as deleted.

    // Find another number whose hash is the same as hf_1, in order to reproduce the problem:
    size_t hf_n = hf_1 + 1; // dummy start value to make sure hf_n != hf_1
    int n = 2;
    assert(hf_n != hf_1);
    while (hf_n != hf_1) {
        n++;
        hf_n = hf(n);
    }
    assert(n != 1);
    assert(hf_n == hf_1);

    cout << "hf_" << n << "=" << hf_n << endl;

    h3.insert(n); // should end up in position x, as that position can be reused.

    assert(h3.size() == 1); // Size should not have changed, since position was reused.

    return 0;
}
