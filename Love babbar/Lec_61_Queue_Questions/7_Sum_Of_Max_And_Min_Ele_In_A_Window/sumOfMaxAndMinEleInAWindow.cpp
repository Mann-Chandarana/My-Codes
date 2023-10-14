#include <bits/stdc++.h>
using namespace std;

// IMPORTANT Question
// T.C. O(N)
// S.C. O(k)

void solve(int arr[], int n, int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);

    // Addition of 1st k size window
    for (int i = 0; i < k; i++)
    {
        while (!maxi.empty() and arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() and arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);
    }

    // Answer for first window
    int ans = 0;
    ans += arr[maxi.front()] + arr[mini.front()];
    cout << ans << " ";

    // Loop for next windows
    for (int i = k; i < n; i++)
    {
        ans = 0;
        // Next window

        // Removal
        while ((!maxi.empty()) and (i - maxi.front() >= k))
        {
            maxi.pop_front();
        }

        while ((!mini.empty()) and (i - mini.front() >= k))
        {
            mini.pop_front();
        }

        // Addition
        while (!maxi.empty() and arr[maxi.back()] <= arr[i])
            maxi.pop_back();

        while (!mini.empty() and arr[mini.back()] >= arr[i])
            mini.pop_back();

        maxi.push_back(i);
        mini.push_back(i);

        ans += arr[maxi.front()] + arr[mini.front()];
        cout << ans << " ";
    }
    cout << endl;
}

int main()
{
    int arr[7] = {2, 5, -1, 7, -3, -1, -2};
    int n = sizeof(arr) / sizeof(int);
    int k = 4;

    solve(arr, n, k);

    return 0;
}