#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n)
{
    string st = to_string(n);
    int i = 0, j = st.length() - 1;

    while (i <= j)
    {
        if (st[i] != st[j])
            return false;
        i++, j--;
    }
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> answer(n);

        for (int i = 0; i < n; i++)
            cin >> answer[i];

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if ((answer[i] ^ answer[j]) == 0 || isPalindrome((answer[i] ^ answer[j])))
                    count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}