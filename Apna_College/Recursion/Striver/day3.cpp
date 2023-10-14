#include "bits/stdc++.h"
using namespace std;

#define ll long long int

// My code:
void subSetWithSumAsK(int arr[], int n, int idx, int k, int &sum, int &ans)
{
    if (sum == k)
    {
        ans++;
        return;
    }
    if (idx == n)
    {
        if (sum == k)
            ans++;
        return;
    }

    if (arr[idx] != 0 and sum + arr[idx] <= k)
    {
        sum += arr[idx];
        subSetWithSumAsK(arr, n, idx, k, sum, ans);
        sum -= arr[idx];
    }
    else if (idx != n - 1)
    {
        sum += arr[idx + 1];
        subSetWithSumAsK(arr, n, idx + 1, k, sum, ans);
        sum -= arr[idx + 1];
    }
    subSetWithSumAsK(arr, n, idx + 1, k, sum, ans);
}

// Code of striver:
int countOfSubSets(int ind, int sum, int arr[], int n)
{
    if (sum == 0)
        return 1;
    if (ind == n)
    {
        // if (sum == 0)
        //     return 1;
        return 0;
    }
    int left = 0, right = 0;
    // When can you pick up a particular index.
    if (arr[ind] <= sum)
    {
        sum -= arr[ind];
        left = countOfSubSets(ind, sum, arr, n);
        sum += arr[ind];
    }

    // Not pick condition, Move to the next index.
    right = countOfSubSets(ind + 1, sum, arr, n);

    return (left + right);
}

void findPaths(vector<vector<int>> arr, int i, int j, string s)
{

    if (i >= arr.size() or j >= arr[0].size())
        return;

    if (i == arr.size() - 1 and j == arr[0].size() - 1)
    {
        cout << s << endl;
        return;
    }

    s += 'D';
    findPaths(arr, i + 1, j, s);
    s.pop_back();

    s += "R";
    findPaths(arr, i, j + 1, s);
    s.pop_back();
}

string dir = "DLRU";
int di[] = {1, 0, 0, -1};
int dj[] = {0, -1, 1, 0};

void findPathsWithFourDir(vector<vector<int>> arr, int i, int j, string s, vector<vector<int>> visited)
{
    // We can go up and left also, so up in (0,0) would go to i = -1, which is not a valid index in a matrix.
    if (i >= arr.size() or j >= arr[0].size() or i < 0 or j < 0 or visited[i][j] == 1)
        return;

    if (i == arr.size() - 1 and j == arr[0].size() - 1)
    {
        cout << s << endl;
        return;
    }

    visited[i][j] = 1;

    // s += "D";
    // findPathsWithFourDir(arr, i + 1, j, s, visited);
    // s.pop_back();

    // s += "L";
    // findPathsWithFourDir(arr, i, j - 1, s, visited);
    // s.pop_back();

    // s += "R";
    // findPathsWithFourDir(arr, i, j + 1, s, visited);
    // s.pop_back();

    // s += "U";
    // findPathsWithFourDir(arr, i - 1, j, s, visited);
    // s.pop_back();

    // Optimizing the upper four groups of statements.
    for (int x = 0; x < 4; x++)
    {
        s += dir[x];
        findPathsWithFourDir(arr, i + di[x], j + dj[x], s, visited);
        s.pop_back();
    }

    visited[i][j] = 0;
}

int main()
{
    // Count the number of subsets with perticular sum.
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0, k = 4, ans = 0;
    // Ans: 4 -> {1,1,1,1}, {1,1,2}, {1,3}, {2,2}. // We can repeat elements, but in forward direction only.

    subSetWithSumAsK(arr, n, 0, k, sum, ans);
    cout << ans << endl;
    cout << countOfSubSets(0, k, arr, n) << endl;

    /*  Matrix Recursion:
        Find paths to reach end index in a matrix. 
    */
    // You can only go right or down.
    // int n = 3, m = 3;
    // vector<vector<int>> arr1(n, vector<int>(m, 0));
    // findPaths(arr, 0, 0, "");

    // Question: Can go in every four directions. Up, Down, Left, Right.
    // Every index should lie only once.

    // n X m  array, for marking visited index.
    // vector<vector<int>> visited(n, vector<int>(m, 0));
    // findPathsWithFourDir(arr1, 0, 0, "", visited);

    return 0;
}