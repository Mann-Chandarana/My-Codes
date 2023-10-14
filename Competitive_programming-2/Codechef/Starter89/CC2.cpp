/******************* DDMM or MMDD *******************/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        string s1 = s.substr(0, 2);
        string s2 = s.substr(3, 5);

        if (stoi(s2) > 12 and stoi(s1) <= 12)
            cout << "MM/DD/YYYY" << endl;

        else if (stoi(s1) > 12 and stoi(s2) <= 12)
            cout << "DD/MM/YYYY" << endl;

        else
            cout << "BOTH" << endl;
    }

    return 0;
}