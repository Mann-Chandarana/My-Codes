#include <bits/stdc++.h>
using namespace std;

#define ll long long int

vector<long long> printFirstNegativeInteger(long long int *A, long long int N, long long int K)
{
    // deque<long long int> dq;
    queue<long long int> dq;
    vector<long long> ans;

    // First window of k size
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
            dq.push(i);
    }
    // if (dq.empty())
    //     ans.push_back(0);
    // else
    //     ans.push_back(A[dq.front()]);

    (dq.empty()) ? ans.push_back(0) : ans.push_back(A[dq.front()]);

    for (int i = K; i < N; i++)
    {
        if (!dq.empty() and (i - dq.front() >= K))
            dq.pop();
        if (A[i] < 0)
            dq.push(i);

        if (dq.size() == 0)
            ans.push_back(0);
        else
            ans.push_back(A[dq.front()]);
    }

    return ans;
}

int main()
{
    ll i;

    ll n;
    cin >> n;

    ll *arr = new ll[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];

    ll k;
    cin >> k;

    vector<ll> ans = printFirstNegativeInteger(arr, n, k);

    for (auto ele : ans)
        cout << ele << " ";
    cout << endl;

    return 0;
}