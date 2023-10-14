/* Dotify playlist */

#include <bits/stdc++.h>
using namespace std;

/* First method :-  Using minheap */

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N, K, L;
        cin >> N >> K >> L;

        priority_queue<int, vector<int>, greater<int>> pq;

        int m, l;

        for (int i = 0; i < N; i++)
        {
            cin >> m >> l;
            if (l == L)
            {
                pq.push(m);
                if (pq.size() > K)
                    pq.pop();
            }
        }
        if (pq.size() < K)
            cout << -1 << endl;
        else
        {
            int answer = 0;
            while (!pq.empty())
            {
                answer += pq.top();
                pq.pop();
            }
            if (answer == 0)
                cout << -1 << endl;
            else
                cout << answer << endl;
        }
    }

    return 0;
}

/* Second method :- Using Sorting */

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N, K, L;
        cin >> N >> K >> L;

        int m, l;
        vector<int> vec;

        for (int i = 0; i < N; i++)
        {
            cin >> m >> l;
            if (L == l)
                vec.push_back(m);
        }
        sort(vec.begin(), vec.end(), greater<int>());
        int answer = 0;
        int i = 0;

        if (vec.size() < K)
            cout << -1 << endl;
        else
        {
            while (K-- and vec.size() > 0)
                answer += vec[i++];

            if (answer == 0)
                cout << -1 << endl;
            else
                cout << answer << endl;
        }
    }

    return 0;
}