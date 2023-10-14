#include <bits/stdc++.h>
using namespace std;

class Stack
{
public:
    int top;
    int *arr;
    int size;

    Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int val)
    {
        if (top >= size - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "Empty stack" << endl;
            return -1;
        }
        return arr[top];
    }

    void pop()
    {
        if (top == -1)
            cout << "Stack already empty" << endl;
        else
            top--;
    }

    int getSize()
    {
        return top + 1;
    }

    bool empty()
    {
        if (top == -1)
            return true;
        return false;
    }
};

int main()
{
    Stack s(3);

    cout << "Is empty: " << s.empty() << endl;
    s.push(11);
    cout << "Top: " << s.getTop() << endl;
    cout << "Is empty: " << s.empty() << endl;
    s.push(12);
    cout << "Top: " << s.getTop() << endl;

    cout << "Size: " << s.getSize() << endl;

    s.push(13);
    s.push(14);
    cout << "Top: " << s.getTop() << endl;
    cout << "Size: " << s.getSize() << endl;

    s.pop();
    s.pop();
    s.pop();
    cout << "Is empty: " << s.empty() << endl;
    s.pop();

    return 0;
}