#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

#define ll long long
#define all(v) v.begin(), v.end()
#define pb push_back
#define pob pop_back
#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int main()
{
    string str;
    cin >> str;

    vi freq(26, 0);

    for (auto ch : str)
        freq[ch - 'A']++;

    int check = 0;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] & 1)
            check++;
    }

    if (check > 1)
        cout << "NO SOLUTION" << endl;
    else
    {
        string answer1, answer2;

        for (int i = 0; i < 26; i++)
        {
            if (freq[i]!=0 and freq[i] % 2 == 0)
            {
                for (int j = 0; j < freq[i] / 2; j++)
                    answer1.pb(i + 'A');
            }
            if (freq[i] & 1)
            {
                for (int j = 0; j < freq[i]; j++)
                    answer2.pb(i + 'A');
            }
        }
        cout << answer1 + answer2;
        reverse(all(answer1));
        cout << answer1 << endl;
        ;
    }

    return 0;
}