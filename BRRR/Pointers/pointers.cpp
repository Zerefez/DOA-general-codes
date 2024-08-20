#include <cassert>
#include <iostream>
using namespace std;

int main()
{
    int a[5] = { 0, 1, 2, 3, 4 };
    int* p = a;

    assert(*p == a[0]);
    cout << "1. *p = " << *p << ", a[0] = " << a[0] << endl;
    cout << "   p = " << p << ", &a[0] = " << &a[0] << endl;

    assert(*p + 1 == a[1]);
    cout << "2. *p + 1 = " << *p + 1 << ", a[1] = " << a[1] << endl;
    cout << "   p = " << p+1 << ", &a[0] = " << &a[1] << endl;

    assert(*(p + 3) == a[3]);
    cout << "3. *(p + 3) = " << *(p + 3) << ", a[3] = " << a[3] << endl;

    p++;
    cout << "4. After p++:" << endl;
    cout << "   *p = " << *p << ", a[0] = " << a[0] << endl;
    cout << "   p = " << p << ", &a[1] = " << &a[1] << endl;

    assert(*p != a[0]);
    assert(*p == a[1]);
    cout << "5. *p = " << *p << ", a[1] = " << a[1] << endl;

}
