// Evaculate to moon

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N, M, H;
        cin >> N >> M >> H;
        vector<long long> cap(N), pow(M);

        for (int i = 0; i < N; i++)
        {
            cin >> cap[i];
        }

        for (int i = 0; i < M; i++)
        {
            cin >> pow[i];
        }

        sort(cap.begin(), cap.end(), greater<int>());
        sort(pow.begin(), pow.end(), greater<int>());
        long long value = 0;
        for (int i = 0; i < min(N, M); i++)
            value += min(cap[i], pow[i] * H);

        cout << value << endl;
    }

    return 0;
}