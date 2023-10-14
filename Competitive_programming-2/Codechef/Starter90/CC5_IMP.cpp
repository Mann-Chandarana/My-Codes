/* Anti Palindrome */

// https://www.codechef.com/START90D/problems/ANTIPALINDR?tab=statement

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        string str;
        cin >> str;
        unordered_map<char, int> mp;

        for (auto ch : str)
            mp[ch]++;

        if (mp.size() == str.size())
            cout << 0 << endl;

        else if (mp.size() == 1)
        {
            if (n % 2 != 0)
                cout << 2 << endl;
            else
                cout << 1 << endl;
        }
        else
        {
            // Find number of odd pairs int the group
            int odd_freq = 0;
            for (auto element : mp)
            {
                if (element.second % &1)
                    odd_freq++;
            }

            if (n % 2 == 0 and odd_freq > 0 || n % 2 != 0 and odd_freq > 1)
                cout << 0 << endl;

            else
                cout << 1 << endl;
        }
    }

    return 0;
}