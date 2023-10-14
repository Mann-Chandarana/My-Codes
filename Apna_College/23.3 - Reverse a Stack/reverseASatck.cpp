#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int ele)
{
    if (st.empty())
    {
        st.push(ele);
        return;
    }

    int topEle = st.top();
    st.pop();
    insertAtBottom(st, ele);
    st.push(topEle);
}

void reverse(stack<int> &st)
{
    if (st.empty())
        return;

    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtBottom(st, ele);
}

int main()
{
    /*
    // Using one extra stack.
    stack<int> st_original, st_reverse;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        st_original.push(i);
    }
    // st_original = 1 2 3 4 5 ..... n (Where n is top element).

    for (int i = 1; i <= n; i++)
    {
        st_reverse.push(st_original.top());
        st_original.pop();
    }
    // st_reverse = n (n-1) (n-2) ...... 1 (Where 1 is top element).

    Without using any extra stack.
    Using recursion.
    */

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    reverse(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}