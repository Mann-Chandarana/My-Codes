/* String Task */

/* https://codeforces.com/problemset/problem/118/A */

#include <bits/stdc++.h>
using namespace std;

#define fastread()  (ios_base:: sync_with_stdio(false),cin.tie(NULL))

bool isVowel(char ch)
{
    if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U'|| ch == 'y' || ch == 'Y')
        return true;
    return false;
}

int main()
{
    fastread();

    string str;
    cin >> str;

    int n = str.length();
    string answer;
    for (int i = 0; i < n; i++)
    {
        if (!isVowel(str[i]))
        {
            answer.pb('.');
            answer.pb(tolower(str[i]));
        }
    }
    cout<<answer<<endl; 

    return 0;
}