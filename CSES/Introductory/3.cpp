#include <bits/stdc++.h>
using namespace std;

#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int main()
{
    fastread();

    string str;
    cin >> str;

    int answer = 1, maxi = INT_MIN, n = str.length();

    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
            answer++;

        else
        {
            maxi = max(maxi, answer);
            answer = 1;
        }
    }
    maxi = max(maxi, answer);
    cout << maxi << endl;

    return 0;
}