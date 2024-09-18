#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
    Queue<int> q;

    cout << "Enqueueing elements..." << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Queue size: " << q.size() << endl;

    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    cout << "Dequeuing elements..." << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;


    cout << "Queue size after dequeues: " << q.size() << endl;


    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;


    cout << "Dequeued: " << q.dequeue() << endl;


    try {
        cout << "Dequeued: " << q.dequeue() << endl;
    }
    catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
