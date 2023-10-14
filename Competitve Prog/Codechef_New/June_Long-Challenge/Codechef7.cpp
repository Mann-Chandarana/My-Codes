/////////////// APGRID

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, N, M;
    cin >> t;

    while (t--)
    {
        cin >> N >> M;
        vector<vector<int>> vec(N, vector<int>(M));

        if (N == M)
        {
            int r_d = 1;
            int c_d = 2;
            int ans = 1;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    vec[i][j] = ans;
                    ans += r_d;
                }
                ans = vec[i][0] + c_d;
                r_d += 2;
            }
        }
        else if (N > M)
        {
            int ans = 1;
            int r_d = N + M;
            int c_d = M;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    vec[i][j] = ans;
                    ans += r_d;
                }
                ans = vec[i][0] + c_d;
                r_d--;
            }
        }
        else
        {
            int ans = 1;
            int r_d = N;
            int c_d = N+M;
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < M; j++)
                {
                    vec[i][j] = ans;
                    ans += r_d;
                }
                ans = vec[i][0] + c_d;
                r_d--;
            }
        }

        for (auto ele : vec)
        {
            for (auto elememt : ele)
            {
                cout << elememt << " ";
            }
            cout << endl;
        }
    }

    return 0;
}