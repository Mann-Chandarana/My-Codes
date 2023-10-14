/*
Chef has a string AA (containing lowercase Latin letters only) of length NN where 
NN is even. He can perform the following operation any number of times:

Swap A_iA 
i
​and A_{i + 2}A 
i+2
​
for any 1 \le i \le (N - 2)1≤i≤(N−2)
Determine if Chef can convert string AA to a palindromic string.

Note: A string is called a palindrome if it reads the same backwards and forwards. 
For example, \texttt{noon}noon and \texttt{level}level are palindromic strings but \texttt{ebb}ebb is not.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, N;
    string str;
    cin >> t;

    while (t--)
    {
        cin >> N;
        cin >> str;

        vector<int> even(26, 0), odd(26, 0);
        for (int i = 0; i < N; i++)
        {
            if (i % 2 == 0)
            {
                odd[str[i] - 'a']++;
            }
            else
            {
                even[str[i] - 'a']++;
            }
        }
        int flag = 0;

        for (int i = 0; i < 26; i++)
        {
            if (odd[i] != even[i])
            {
                flag = 1;
                break;
            }
        }

        if (flag)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}