/* Blobby Volley Scores */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, scoreA = 0, scoreB = 0;
        cin >> n;

        string s;
        cin >> s;

        if (s[0] == 'A')
            scoreA++;

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == s[i - 1])
                s[i] == 'A' ? scoreA++ : scoreB++;
        }

        cout << scoreA << " " << scoreB << endl;
    }

    return 0;
}