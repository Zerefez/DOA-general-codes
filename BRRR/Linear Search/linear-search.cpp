#include <iostream>
#include <vector>
#include <algorithm>

#include "linear-search.h"

using namespace std;

#define N		1000
#define MAX 	1000

int main(void) {
    int i, j;
    vector<int> v;
    vector<int>::iterator itr;

    srand(time(0));
    for (i = 0; i < N; i++) {
        v.push_back(rand() % MAX);
    }

    /* Now let us print the vector through iterator */
    for (itr = v.begin(); itr != v.end(); itr++) {
        cout << *itr << " ";
    }
    cout << endl;

    j = rand() % MAX;

    /* Now search using linear search. */
    itr = linearSearch(v.begin(), v.end(), j);
    if (itr != v.end()) {
        cout << "Found element: " << *itr << endl;
    }
    else {
        cout << "Element not found: " << j << endl;
    }

    return 0;
}
