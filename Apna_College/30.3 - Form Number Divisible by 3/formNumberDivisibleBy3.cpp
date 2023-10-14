#include "bits/stdc++.h"
using namespace std;

int formNumber(int arr[], int n, int startPos, int k)
{
    string ansString = "";
    for (int i = startPos; i < startPos + k; i++)
    {
        ansString += to_string(arr[i]);
    }

    return stoi(ansString);
}

int numberDivisibleBy3_myCode(int arr[], int n, int k)
{
    if (n < k)
        return -1;
    int start = 0, end = 0, sum = 0, pos = -1;
    for (end = 0; end < k; end++)
    {
        sum = sum + arr[end];
        pos = start;
    }
    if (sum % 3 == 0)
    {
        return formNumber(arr, n, start, k);
    }

    for (end = k; end < n; end++)
    {
        sum -= arr[start];
        start++;
        sum += arr[end];
        if (sum % 3 == 0)
        {
            return formNumber(arr, n, start, k);
        }
    }

    return -1;
}

void numberDivisibleBy3_ApnaCollege(vector<int> arr, int k)
{
    pair<int, int> ans;
    int sum = 0;

    for (int i = 0; i < k; i++)
        sum += arr[i];

    bool found = false;
    if (sum % 3 == 0)
    {
        ans = make_pair(0, k - 1);
        found = true;
    }

    for (int i = k; i < arr.size(); i++)
    {
        if (found)
        {
            break;
        }
        sum = sum + arr[i] - arr[i - k];
        if (sum % 3 == 0)
        {
            ans = make_pair(i - k + 1, i);
            found = true;
        }
    }

    if (!found)
    {
        ans = make_pair(-1, 0);
    }
    if (ans.first == -1)
    {
        cout << "No such sub array exists" << endl;
    }
    else
    {
        for (int i = ans.first; i <= ans.second; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    //     cin >> arr[i];
    // int k;
    // cin >> k;

    // int sum = numberDivisibleBy3_myCode(arr, n, k);
    // cout << "Output of my code: " << endl;
    // if (sum == -1)
    //     cout << "Cannot get a number" << endl;
    // else
    //     cout << "Number divisible by 3 is " << sum << endl;
    // cout << endl
    //      << endl;

    // vector<int> arr1 = {84, 23, 45, 12, 56, 82};
    // int k1 = 3;
    // cout << "Output of Apna College code: " << endl;
    // numberDivisibleBy3_ApnaCollege(arr1, k1);

    return 0;
}