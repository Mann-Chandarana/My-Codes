/* X OR Y :- Easy https://www.codingninjas.com/studio/problems/x-or-y_972995?utm_source=youtube&utm_medium=affiliate&utm_campaign=parikh_youtube&leftPanelTab=0 */

#include <bits/stdc++.h>
using namespace std;

long long findPairY(long long X)
{
    int n = log2(X) + 1; // It will show the index of least significant bits
    string temp = "";

    for (int i = 0; i < n; i++)
    {
        if ((1LL << i) & X)
            temp += '1';
        else
            temp += '0';
    }

    long long ans = 0;

    for (int i = 0; i < n / 2; i++)
    {
        if (temp[i] == temp[n - i - 1])
            continue;

        if (temp[i] == '0')
            ans += (1LL << i);

        else
            ans += (1LL << (n - i - 1));
    }
    return ans;
}

int main()
{
    cout << findPairY(6) << endl;
    return 0;
}