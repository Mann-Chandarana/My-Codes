#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class queue
{
    node *front;
    node *back;

public:
    queue()
    {
        front = NULL;
        back = NULL;
    }
    void push(int val)
    {
        node *n = new node(val);
        if (front == NULL)
        {
            back = n;
            front = n;
            return;
        }
        back->next = n;
        back = back->next;
    }
    void pop()
    {
        if (front == NULL)
        {
            cout << "No element int queue to pop" << endl;
            return;
        }
        node *toDelete = front;
        front = front->next;
        delete toDelete;
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "Empty Queue ";
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        if (front == NULL)
        {
            return true;
        }
        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.peek() << endl;
    q.pop();

    cout << q.empty() << endl;

    return 0;
}