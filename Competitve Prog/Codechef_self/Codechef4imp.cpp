#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string p, s1, s2;
        cin >> p;

        if (p.size() % 2 == 0)
        {
            s1 = p.substr(0, p.size() / 2);
            s2 = p.substr(p.size() / 2, p.size());
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
        }
        else
        {
            s1 = p.substr(0, p.size() / 2);
            s2 = p.substr((p.size() / 2) + 1, p.size());
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
        }

        if (s1 == s2)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}