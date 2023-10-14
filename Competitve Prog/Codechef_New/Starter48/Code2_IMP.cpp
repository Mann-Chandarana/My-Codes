//////////// Positive array

#include <bits/stdc++.h>
using namespace std;

bool isPositive(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] - 1 < i)
        {
            return false;
        }
    }
    return true;
}

void isMatch(vector<int> &pointer, int value, int &count)
{
    for (int i = 0; i < pointer.size(); i++)
    {
        // cout << "Value of pointer is " << pointer[i] << " value is " << value << endl;
        if (pointer[i] <= value)
        {
            pointer[i]+=1;
            return;
        }

        if (pointer[i] == INT_MAX)
        {
            count++;
            pointer[i] = 1;
            return;
        }
    }
}

int main()
{
    int t, N;
    cin >> t;

    while (t--)
    {
        cin >> N;
        vector<int> vec(N);
        vector<int> pointer(N, INT_MAX);

        for (int i = 0; i < N; i++)
        {
            cin >> vec[i];
        }

        int ans = 1;

        if (isPositive(vec))
        {
            cout << ans << endl;
        }
        else
        {
            sort(vec.begin(), vec.end());
            ans = 0;
            for (int i = 0; i < N; i++)
            {
                isMatch(pointer, vec[i]-1, ans);
                // cout << "Count inside loop is " << ans << endl;
            }
            cout << ans << endl;
        }
    }

    return 0;
}