#include <iostream>
#include <vector>
using namespace std;

void minHeapify(vector<int>& arr, int i, int n) {
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, smallest, n);
    }
}

int main() {
    vector<int> arr = { 59,44,79,17,54,32,31,12,7,4,1 };

    cout << "Original array: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    // Perform heapify operation on min-heap
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        minHeapify(arr, i, arr.size());

    cout << "\nMin-Heap after heapify operation: ";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";

    return 0;
}
