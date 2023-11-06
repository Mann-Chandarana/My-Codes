// ND

/* 1300:- D. Prefix Permutation Sums */

/* https://codeforces.com/problemset/problem/1851/D */

/*
Here we have to consider two cases where last element is presnt or last element is not present
1) Last element is present 
   a) The element is deleted from the beginning 
   b) The element is deleted from the middle

2) Last element is not present 
   a) The element is deleted from the end  

*/

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

        long long A[n];
        for (int i = 0; i < (n - 1); ++i)
        {
            cin >> A[i];
        }

        long long sum = n;
        sum *= (sum + 1ll);
        sum /= 2ll;

        if (A[n - 2] > sum)
        {
            cout << "NO\n";
            continue;
        }

        set<long long> avail;
        for (int i = 1; i <= n; ++i)
            avail.insert(i);
        int c = 0;
        long long val = -1, star = -1;
        int f = 0;
        for (int i = 1; i < (n - 1); ++i)
        {
            long long dif = A[i] - A[i - 1];
            if (avail.find(dif) == avail.end())
            {
                val = dif;
            }
            else
                avail.erase(dif);
        }

        if (A[n - 2] == sum)
        {
            // either from start
            if (avail.size() == 2)
            {
                // it means from start
                long long cur_sum = 0;
                for (auto &x : avail)
                    cur_sum += x;

                if (cur_sum == A[0])
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
            else if (avail.size() > 3)
                cout << "NO\n";
            else
            {
                // it means from middle
                if (avail.find(A[0]) == avail.end())
                {
                    cout << "NO\n";
                }
                else
                {
                    avail.erase(A[0]);
                    long long cur_sum = 0;
                    for (auto &x : avail)
                        cur_sum += x;
                    if (cur_sum == val)
                        cout << "YES\n";
                    else
                        cout << "NO\n";
                }
            }
        }
        else
        {
            // last value is removed
            if (avail.size() > 2)
                cout << "NO\n";
            else if (avail.find(A[0]) == avail.end())
            {
                cout << "NO\n";
            }
            else
                cout << "YES\n";
        }
    }
}