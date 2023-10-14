#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        ll s1_1 = 0, s1_0 = 0, s2_0 = 0, s2_1 = 0;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] == '1')
            {
                s1_1++;
            }
            if (s1[i] == '0')
            {
                s1_0++;
            }
            if (s2[i] == '1')
            {
                s2_1++;
            }
            if (s2[i] == '0')
            {
                s2_0++;
            }
        }
        ll max_1 = min(s1_1, s2_0) + min(s2_1, s1_0);
        for (ll i = 0; i < s1.length(); i++)
        {
            if (i < max_1)
                cout << '1';
            else
                cout << '0';
        }
        cout << endl;
    }

    return 0;
}