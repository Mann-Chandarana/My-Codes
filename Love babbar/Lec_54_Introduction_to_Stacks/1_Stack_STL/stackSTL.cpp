#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> s)
{
    cout << "Stack from top to bottom: ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void reversePrintRec(stack<int> s)
{
    if (s.empty())
        return;

    int topEle = s.top();
    s.pop();
    reversePrintRec(s);

    cout << topEle << " ";
}

void printTop(stack<int> &s)
{
    if (s.empty())
        cout << "Empty stack" << endl;
    else
        cout << s.top() << endl;
}

int main()
{
    // Creation of stack
    stack<int> s;

    cout << "Is empty: " << s.empty() << endl;

    // Code crash if we use pop operation on empty stack 
    // s.pop();

    // Code crash if we try to print the top element for empty stack:
    // cout << s.top() << endl;
    printTop(s);

    // Push operation
    s.push(11);
    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);
    s.emplace(16); // emplace is a bit faster than push
    cout << "Is empty: " << s.empty() << endl;

    // Top element:
    cout << "Top element: " << s.top() << endl;

    // Size:
    cout << "Size: " << s.size() << endl;

    // Pop operation
    // int ele = s.pop(); // Error, pop has no return type
    s.pop();
    cout << "Top element after pop: " << s.top() << endl;
    cout << "Size after pop: " << s.size() << endl;

    printStack(s);
    cout << "Top: " << s.top() << endl;

    cout << "Stack from bottom to top: ";
    reversePrintRec(s);
    cout << "\nTop: " << s.top() << endl;

    return 0;
}