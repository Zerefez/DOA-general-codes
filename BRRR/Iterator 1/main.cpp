#include <cassert>
#include <iostream>
#include <iterator> // for iterators
#include <vector>   // for vectors

using namespace std;

int main()
{
    vector<int> ar = { 1, 2, 3, 4, 5 };
    vector<int>::iterator ptr = ar.begin();
    ptr++;ptr++;
    assert((*ptr) == 3);  // True or False?

    ptr += 2;
    (*ptr) = 10;

    assert(ar[3] == 10);  // True or False?
    assert(ar[4] == 10);  // True or False?
    assert(ar[5] == 10);  // True or False?

    // Displaying vector elements using begin() and end()
    cout << "The vector elements are : ";
    for (ptr = ar.begin(); ptr < ar.end(); ptr++)
         cout << *ptr << " ";

    return 0;
}

// Compile with: cl /EHsc .\main.cpp
