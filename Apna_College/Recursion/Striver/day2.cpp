#include "bits/stdc++.h"
using namespace std;

#define ll long long int

// IMP:
void printSubSeq(int start, int arr[], int n, vector<int> &v)
{
    if (start >= n)
    {
        // print(v);
        for (auto ele : v)
            cout << ele << " ";
        cout << endl;
        return;
    }
    v.push_back(arr[start]); // For pick condition.
    printSubSeq(start + 1, arr, n, v);
    v.pop_back(); // For not pick condition.
    printSubSeq(start + 1, arr, n, v);
}

void subSetsWithSumDivisibleByK(int arr[], int n, int start, vector<int> &v, int k, int &sum)
{
    if (start == n)
    {
        if (v.size() != 0 and sum % k == 0)
        {
            for (auto ele : v)
                cout << ele << " ";
            cout << endl;
        }
        return;
    }
    v.push_back(arr[start]);
    sum += arr[start];
    subSetsWithSumDivisibleByK(arr, n, start + 1, v, k, sum);
    sum -= v.back();
    v.pop_back();
    subSetsWithSumDivisibleByK(arr, n, start + 1, v, k, sum);
}

int totalSubSetsWithSumDivisibleByK(int start, int arr[], int n, int &sum, int k)
{
    if (start == n) // {} sub set is also considered.
    {
        if (sum % k == 0)
            return 1;
        return 0;
    }
    sum += arr[start];
    int picked = totalSubSetsWithSumDivisibleByK(start + 1, arr, n, sum, k);
    sum -= arr[start];
    int notPicked = totalSubSetsWithSumDivisibleByK(start + 1, arr, n, sum, k);

    return picked + notPicked;
}

int main()
{
    // Printing Sub-Sequencies. IMPORTANT.
    // {1, 3, 2}. N = 3. Total sub sequencies: 2^N = 2^3 = 8.
    // {[Y/N], [Y/N], [Y/N], ......, [Y/N]}. 2 options for each positions.
    int arr[] = {1, 3, 2, 4};
    vector<int> v;
    int n = sizeof(arr) / sizeof(arr[0]);
    printSubSeq(0, arr, n, v);

    // // Question: Print the subsets whose sum is divisible by K.
    // int arr1[] = {4, 2, 1, 3};
    // int k = 3;
    // int n1 = sizeof(arr1) / sizeof(arr1[0]);
    // vector<int> v1;
    // int sum = 0;
    // cout << "Total sun sets with sum divisible by k: " << totalSubSetsWithSumDivisibleByK(0, arr1, n1, sum, k) - 1 << endl; // Because of the empty subset
    // sum = 0;
    // subSetsWithSumDivisibleByK(arr1, n1, 0, v1, k, sum);

    return 0;
}