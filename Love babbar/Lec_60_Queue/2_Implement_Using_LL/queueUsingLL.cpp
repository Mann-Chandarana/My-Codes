#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Stack
{
public:
    Node *head;
    Node *tail;

    Stack()
    {
        head = NULL;
        tail = NULL;
    }

    void push(int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }

    int top()
    {
        if (tail == NULL)
        {
            cout << "Empty stack ";
            return -1;
        }
        return tail->data;
    }

    int size()
    {
        int count = 0;
        Node *temp = head;
        while (temp)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void pop()
    {
        if (tail == NULL)
        {
            cout << "Stack is already empty" << endl;
            return;
        }
        else if (tail == head)
        {
            tail = NULL;
            head = NULL;

            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            Node *del = tail;
            tail = temp;
            tail->next = NULL;

            delete del;
        }
    }

    bool empty()
    {
        if(head == NULL)
            return true;
        
        return false;
    }
};

class Queue
{
    Node *head;
    Node *tail;
    int qSize;
public:

    Queue()
    {
        head = NULL;
        tail = NULL;

        qSize = 0;
    }

    void push(int val)
    {
        if (head == NULL)
        {
            head = new Node(val);
            tail = head;
        }
        else
        {
            tail->next = new Node(val);
            tail = tail->next;
        }
        qSize++;
    }

    int front()
    {
        if (head == NULL)
        {
            cout << "Queue is empty ";
            return -1;
        }
        else
        {
            return head->data;
        }
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Queue already empty" << endl;
            return;
        }
        else if (head == tail) // Only one element in the queue
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *del = head;
            head = head->next;

            delete del;
        }
        qSize--;
    }

    int size()
    {
        return qSize;
    }

    bool empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
};

int main()
{
    Queue q;

    cout << "Size: " << q.size() << endl;
    cout << "Empty: " << q.empty() << endl;

    q.push(23);
    q.push(3);
    q.push(16);
    q.push(7);

    cout << "Front: " << q.front() << endl;

    cout << "Size: " << q.size() << endl;
    cout << "Empty: " << q.empty() << endl;

    q.pop();
    q.pop();

    cout << "Size after pop: " << q.size() << endl;
    cout << "Empty after pop: " << q.empty() << endl;

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    cout << "Front: " << q.front() << endl;
    cout << "Size after pop: " << q.size() << endl;
    cout << "Empty after pop: " << q.empty() << endl;

    q.push(98);
    // q.push(178);
    cout << "Size after pop: " << q.size() << endl;
    cout << "Empty after pop: " << q.empty() << endl;
    cout << "Front: " << q.front() << endl;

    return 0;
}