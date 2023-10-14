#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void insertAtBottom(stack<int> &s, int &ele)
{
    if (s.empty())
    {
        s.push(ele);
        return;
    }

    int topEle = s.top();
    s.pop();

    insertAtBottom(s, ele);

    s.push(topEle);
}

void reverseStack(stack<int> &s)
{
    /*
    while (!s.empty())
    {
        temp.push(s.top());
        s.pop();
    }

    while (!temp.empty())
    {
        insertAtBottom(s, temp.top());
        temp.pop();
    }
    */

    // Without using temp

    if (s.empty())
        return;

    int topEle = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s, topEle);
}

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout << "Before reverse: ";
    printStack(s);

    stack<int> temp;

    reverseStack(s); // T.C.: O(N^2) and S.C.: O(N)

    cout << "After reverse: ";
    printStack(s);

    cout << "\nMain end..\n";
    return 0;
}