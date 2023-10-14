// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
} // } Driver Code Ends

// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    // Q: 1 2 3 4 5
    // k: 3
    stack<int> st; // To reverse

    for (int i = 0; i < k; i++)
    {
        if (!q.empty())
        {
            st.push(q.front());
            q.pop();
        }
    }
    // st: (from top to bottom) 3 2 1

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    // q: 4 5 3 2 1
    // Expected op: 3 2 1 4 5 

    // Put remaining first (size - k) elements of q to back of that q.
    int count = q.size() - k;
    while (count--)
    {
        int ele = q.front();
        q.pop();
        q.push(ele);
    }

    return q;
}