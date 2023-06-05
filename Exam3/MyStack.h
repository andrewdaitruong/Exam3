#pragma once
#pragma once
#include <vector>
using namespace std;

template<class T>
class MyStack
{
private:
    vector<T> container;
    int maxSize;
public:
    MyStack(int size) : maxSize(size)
    {
        container.clear();
    }

    bool isEmpty() const
    {
        return container.empty();
    }

    bool isFull() const
    {
        return container.size() >= maxSize;
    }

    T top() const
    {
        if (isEmpty())
            return -1;

        return container.back();
    }

    void push(const T element, const T element1)
    {
        if (isFull())
        {
            throw runtime_error("Stack is full");
        }
        T value = rand() % 100;

        container.push_back(value);
        cout << "Push(" << value << ")\n";
    }

    void pop()
    {
        if (!isEmpty())
        {
            T topElement = container.back();
            container.pop_back();
            cout << "Popped(" << topElement << ")\n";
        }
    }

    void clear()
    {
        container.clear();
    }

    void pop1()
    {
        if (!isEmpty())
        {
            T topElement = container.back();
            container.pop_back();
            cout << topElement;
        }
    }

    bool isLetter(char ch)
    {
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
    }
};
