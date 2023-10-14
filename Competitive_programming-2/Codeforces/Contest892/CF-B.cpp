/* https://codeforces.com/contest/1859/problem/B */

/*
Approach :-
1) Here in this question we first find the minimum of all the second Minimum of all the arrys and stores its index
2) Then we add all the minimum element of the array in the the arr[index]
3) Then we find the minimum of all the array and we will find the sum
*/

#include <bits/stdc++.h>
using namespace std;

/* Editorial Solution */

#define all(v) v.begin(), v.end()

void solve()
{
    int n;
    cin >> n;

    int minn = INT_MAX;
    vector<int> min2;

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<int> v(m);
        for (auto &el : v)
            cin >> el;

        int minel = *min_element(all(v));
        minn = min(minn, minel);
        v.erase(find(all(v), minel));
        min2.push_back(*min_element(all(v)));
    }
    cout << minn + accumulate(all(min2), 0ll) - *min_element(all(min2)) << "\n";
}

/* Solution -2 */

void solve()
{
    int n;
    cin >> n;

    vector<int> vec[n];
    vector<int> mini(n, 0);
    vector<int> second_minimum(n, -1);

    for (int i = 0; i < n; i++)
    {
        int size;
        cin >> size;
        int minimum = INT_MAX;

        for (int j = 0; j < size; j++)
        {
            int value;
            cin >> value;
            vec[i].push_back(value);
            minimum = min(vec[i][j], minimum);
        }
        sort(vec[i].begin(), vec[i].end());
        mini[i] = vec[i][0];
        if (vec[i].size() > 1)
            second_minimum[i] = vec[i][1];
    }

    if (n == 1)
        cout << mini[0] << endl;
    else
    {
        int lowest = INT_MAX, index;

        for (int i = 0; i < n; i++)
        {
            if (second_minimum[i] != -1 and lowest > second_minimum[i])
            {
                index = i;
                lowest = second_minimum[i];
            }
        }

        int minimum_lowest = mini[index];
        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            if (i != index)
            {
                minimum_lowest = min(minimum_lowest, mini[i]);
                sum += second_minimum[i];
            }
        }
        sum += minimum_lowest;

        cout << sum << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}