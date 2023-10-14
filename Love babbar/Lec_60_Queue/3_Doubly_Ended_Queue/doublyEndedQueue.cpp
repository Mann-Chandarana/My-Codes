#include <bits/stdc++.h>
using namespace std;

// Implementation using LL

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

class Dequeue
{
    Node *head;
    Node *tail;
    int dqSize;

public:
    Dequeue()
    {
        head = NULL;
        tail = NULL;
        dqSize = 0;
    }

    void push_front(int val)
    {
        dqSize++;
        if (head == NULL) // Empty queue
        {
            head = new Node(val);
            tail = head;
            return;
        }
        else
        {
            Node *temp = new Node(val);
            temp->next = head;
            head = temp;
        }
    }

    void push_back(int val)
    {
        dqSize++;
        if (head == NULL) // Empty queue
        {
            head = new Node(val);
            tail = head;
            return;
        }
        tail->next = new Node(val);
        tail = tail->next;
    }

    void pop_front()
    {
        if (head == NULL)
        {
            cout << "Queue is already empty" << endl;
            return;
        }
        
        dqSize--;
        if (head == tail) // Single element
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            Node *del = head;
            head = head->next;

            del->next = NULL;
            delete del;
        }
    }

    void pop_back()
    {
        if (head == NULL)
        {
            cout << "Queue is already empty" << endl;
            return;
        }
        if (head == tail) // Single element
        {
            head = NULL;
            tail = NULL;
        }
        else // O(size), In array this can be done in O(1)
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
        dqSize--;
    }

    int front()
    {
        if (head == NULL)
        {
            cout << "Queue is empty ";
            return -1;
        }
        return head->data;
    }

    int back()
    {
        if (head == NULL)
        {
            cout << "Queue is empty ";
            return -1;
        }
        return tail->data;
    }

    bool empty()
    {
        return (head == NULL);
    }

    int size()
    {
        return dqSize;
    }
};

int main()
{
    Dequeue dq;

    cout << "Is empty: " << dq.empty() << endl;
    cout << "Size: " << dq.size() << endl;

    dq.push_front(23);
    dq.push_back(45);

    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;

    dq.push_back(89);
    dq.push_front(10);

    cout << "Size: " << dq.size() << endl;

    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;

    dq.pop_back();
    cout << "Back: " << dq.back() << endl;

    cout << "Size: " << dq.size() << endl;

    dq.pop_back();
    dq.pop_front();

    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl;

    dq.pop_back();
    dq.pop_front();
    dq.pop_back();

    cout << "Is empty: " << dq.empty() << endl;
    cout << dq.front() << endl;
    cout << dq.back() << endl;

    dq.push_back(999);
    dq.push_front(68);

    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;
    cout << "Size: " << dq.size() << endl;

    return 0;
}