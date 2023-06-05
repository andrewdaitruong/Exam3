#pragma once
#include <queue>
#include <stdexcept>
using namespace std;

template<class T>
class MyQueue
{
private:
    queue<T> container;
    int maxSize = 0;

public:
    MyQueue(int size) : maxSize(size)
    {
        container = queue<T>();
    }

    bool isEmpty() const
    {
        return container.empty();
    }

    bool isFull() const
    {
        return container.size() >= maxSize;
    }

    T back() const
    {
        if (isEmpty())
            throw runtime_error("ERROR: Queue is empty.");
        return container.back();
    }

    T front() const
    {
        if (isEmpty())
            throw runtime_error("ERROR: Queue is empty.");
        return container.front();
    }

    void enqueue(const T& element)
    {
        if (isFull())
            throw runtime_error("ERROR: Cannot enqueue an element. Queue is full.");
        container.push(element);
        cout << "Enqueue(" << element << ")\n";
    }

    void dequeue()
    {
        if (isEmpty())
            throw runtime_error("ERROR: Cannot dequeue an element. Queue is empty.");
        T frontElement = container.front();
        container.pop();
        cout << "Dequeue(" << frontElement << ")\n";
    }
};