#include <bits/stdc++.h>
using namespace std;

// Algo in the book

/*
Invalid string
1)  {{{{
2)  }}}}}
3)  }}}}{{{{

--------------------------------------- 
1) odd give -1
2) i/p string remove valid vala part
*/

int minBracketReversal(string s)
{
    if (s.length() & 1)
        return -1;

    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
            st.push(s[i]);

        else
        {
            if (!st.empty() and st.top() == '{')
                st.pop();

            else
                st.push(s[i]);
        }
    }

    int a = 0, b = 0;

    while (!st.empty())
    {
        if (st.top() == '{')
            a++;
        else
            b++;
        st.pop();
    }

    return (a + 1) / 2 + (b + 1) / 2;
}

int main()
{
    string s;
    cin >> s;

    cout << minBracketReversal(s) << endl;

    return 0;
}