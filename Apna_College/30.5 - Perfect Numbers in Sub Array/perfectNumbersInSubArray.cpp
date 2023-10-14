#include "bits/stdc++.h"
using namespace std;

bool isPerfect(int n)
{
    int sum = 1;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (i == n / i)
                sum += i;
            else
                sum += i + n / i;
        }
    }
    if (sum == n and n != 1)
        return true;
    return false;
}

int maximumPerfectNumbers_myCode(vector<int> arr, int k)
// For a sub array with size k, this function will return the maximum numbers of perfect numbers a subarray with k size contains.
{
    if (k > arr.size())
    {
        cout << "Invalid inputs" << endl;
        return -1;
    }

    int count = 0;
    deque<pair<int, char>> deq;
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        if (isPerfect(arr[i]))
        {
            count++;
            deq.push_back(make_pair(arr[i], 'y'));
        }
        else
        {
            deq.push_back(make_pair(arr[i], 'n'));
        }
    }
    ans = count;
    for (int i = k; i < arr.size(); i++)
    {
        if (deq.front().second == 'y')
        {
            count--;
            deq.pop_front();
        }
        else if (deq.front().second == 'n')
        {
            deq.pop_front();
        }
        if (isPerfect(arr[i]))
        {
            deq.push_back(make_pair(arr[i], 'y'));
            count++;
        }
        else
        {
            deq.push_back(make_pair(arr[i], 'n'));
        }
        ans = max(ans, count);
    }

    return ans;
}

int maxNumberOfPerfects_apnaCollege(vector<int> arr, int k)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (isPerfect(arr[i]))
            arr[i] = 1;
        else
            arr[i] = 0;
    }
    int sum = 0, ans;
    if (arr.size() < k)
    {
        cout << "Invalid values" << endl;
        return -1;
    }
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    ans = sum;
    for (int i = k; i < arr.size(); i++)
    {
        sum = sum - arr[i - k] + arr[i];
        ans = max(ans, sum);
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (auto &i : arr)
        cin >> i;

    int k;
    cin >> k;
    cout << "Output of my code: " << endl;
    cout << maximumPerfectNumbers_myCode(arr, k) << endl;

    cout << endl;

    cout << "Output of apna college code: " << endl;
    cout << maxNumberOfPerfects_apnaCollege(arr, k) << endl;

    return 0;
}