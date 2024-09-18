#pragma once

#include "Stack.h"

template <typename Object>
class Queue
{
private:
    Stack<Object> s1;
    Stack<Object> s2;

public:
    Queue()
    {
    }

    ~Queue()
    {
        clear();
    }

    int size()
    {
        return s1.size() + s2.size();
    }

    bool empty()
    {
        return s1.size() && s2.size();
    }

    void clear()
    {
        s1.clear();
        s2.clear();
    }

    void enqueue(const Object x)
    {
        cout << "Queue push: " << x << endl;
        s1.push(x);
    }


    Object dequeue()
    {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.pop());
            }
        }
        if (!s2.empty()) {
            cout << "Queue pop: " << s2.top() << endl;
            return s2.pop();
        }
        else {
            throw runtime_error("Queue is empty");
        };
    }

    Object front()
    {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.pop());
            }
        }

        if (!s2.empty()) {
            return s2.top();
        }
        else {
            throw runtime_error("Queue is empty");
        }
    }

    Object back()
    {
        if (!s1.empty()) {
            return s1.top();
        }
        else if (!s2.empty()) {
            return s2.top();
        }
        else {
            throw runtime_error("Queue is empty");
        }
    }

};