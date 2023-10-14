#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
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

int main()
{

    Stack s;
    s.push(10);
    cout << "Size: " << s.size() << endl;
    cout << "Empty: " << s.empty() << endl;
    s.pop();
    s.pop();
    cout << "Empty: " << s.empty() << endl;
    cout << s.top() << endl;

    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << endl;

    cout << "\nMain end" << endl;
    return 0;
}