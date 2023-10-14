///////// More optimised approach for finding Factors

#include <bits/stdc++.h>
using namespace std;

void printfactors(int n)
{
    vector<pair<int, int>> factors;
    int cnt;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            // keep dividing it by i till it is divided
            while (n % i == 0)
            {
                cnt++;
                n = n / i;
            }
            factors.push_back({i, cnt});
        }
    }
    if (n != 1)
    {
        factors.push_back({n, 1});
    }

    for (auto p : factors)
    {
        cout << p.first << "^" << p.second << endl;
    }
    return;
}

int main()
{

    return 0;
}