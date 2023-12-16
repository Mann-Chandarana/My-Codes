#include <bits/stdc++.h>
using namespace std;

#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

set<string> st;

void solve(int index, string &s)
{
    if (index == s.length())
        st.insert(s);

    for (int i = index; i < s.length(); i++)
    {
        swap(s[index], s[i]);
        solve(index + 1, s);
        swap(s[index], s[i]);
    }
}

int main()
{
    fastread();

    string s;
    cin >> s;

    solve(0, s);

    cout << st.size() << endl;

    for (auto element : st)
        cout << element << endl;

    return 0;
}