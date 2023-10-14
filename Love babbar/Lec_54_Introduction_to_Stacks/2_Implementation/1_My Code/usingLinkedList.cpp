#include <bits/stdc++.h>
using namespace std;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T d)
    {
        data = d;
        next = NULL;
    }
};

template <class T>
class Stack
{
public:
    Node<T> *head;
    Node<T> *tail;

    Stack()
    {
        head = NULL;
        tail = NULL;
    }

    void push(T val)
    {
        if (head == NULL)
        {
            head = new Node<T>(val);
            tail = head;
        }
        else
        {
            tail->next = new Node<T>(val);
            tail = tail->next;
        }
    }

    T top()
    {
        if (tail == NULL)
        {
            cout << "Stack already empty" << endl;
            return -1;
        }
        return tail->data;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack is already empty" << endl;
            return;
        }
        if (head == tail)
        {
            Node<T> *del = head;
            head = NULL;
            tail = NULL;
            delete del;
            return;
        }
        Node<T> *temp = head;
        Node<T> *del = tail;
        while (temp->next and temp->next != tail)
        {
            temp = temp->next;
        }
        tail = temp;
        tail->next = NULL;
        delete del;

        return;
    }

    int size()
    {
        int count = 0;
        Node<T> *temp = head;

        while (temp)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    bool empty()
    {
        if (head == NULL)
            return true;
        return false;
    }
};

template <class T>
void print(Stack<T> s)
{
    while (s.head)
    {
        cout << s.head->data << " ";
        s.head = s.head->next;
    }
    cout << endl;
}

template <class T>
void change(Stack<T> &s)
{
    s.push(999);
}

int main()
{
    // Stack of int type

    Stack<int> s;

    s.pop();

    if (s.empty())
        cout << "Empty" << endl;
    else
        cout << "Not empty" << endl;

    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);

    cout << "Size: " << s.size() << endl;

    cout << "Top element before pop: " << s.top() << endl;

    s.pop();

    cout << "Top element after pop: " << s.top() << endl;

    if (s.empty())
        cout << "Empty" << endl;
    else
        cout << "Not empty" << endl;

    cout << "Stack: ";
    print(s);
    cout << "Top ele: " << s.top() << endl;
    cout << "Change function called" << endl;
    change(s);
    cout << "Top ele: " << s.top() << endl;

    // Stack of string type
    /*

    Stack<string> s1;
    s1.push("Parth");
    s1.push("Rathod");

    cout << s1.top() << endl;
    s1.pop();
    cout << "Size: " << s1.size() << endl;
    cout << s1.top() << endl;

    */

    return 0;
}