#include "bits/stdc++.h"
using namespace std;

void printSubSeq(vector<int> &arr, int start, int k, int &sum, vector<int> &v)
{
    if (start == arr.size())
    {
        if (sum % k == 0 and v.size() != 0)
        {
            for (auto ele : v)
                cout << ele << " ";
            cout << endl;
        }
        exit(0); // Will exit from the entire program(code).
        return;
    }

    v.push_back(arr[start]);
    sum += arr[start];
    printSubSeq(arr, start + 1, k, sum, v);
    sum -= arr[start];
    v.pop_back();
    printSubSeq(arr, start + 1, k, sum, v);
}

bool printOnlyOneSubSeq(vector<int> &arr, int start, int k, int &sum, vector<int> &v)
{
    if (start == arr.size())
    {
        if (sum % k == 0 and v.size() != 0)
        {
            for (auto ele : v)
                cout << ele << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    v.push_back(arr[start]);
    sum += arr[start];
    if (printOnlyOneSubSeq(arr, start + 1, k, sum, v) == true)
        return true;
    sum -= arr[start];
    v.pop_back();
    if (printOnlyOneSubSeq(arr, start + 1, k, sum, v) == true)
        return true;
}

// O(3N)
bool isSafe(int row, int col, vector<vector<int>> &mat)
{
    // For upper-left diagonal, row-1 and col-1.
    for (int i = row, j = col; i >= 0 and j >= 0; i--, j--)
    {
        if (mat[i][j] == 1)
            return false;
    }
    // For left, row and col - 1.
    for (int j = col; j >= 0; j--)
    {
        if (mat[row][j] == 1)
            return false;
    }
    // For lower-left diagonal, row + 1 and col - 1.
    for (int i = row, j = col; i < mat.size() and j >= 0; i++, j--)
    {
        if (mat[i][j] == 1)
            return false;
    }

    return true;
}

bool NQueen(int col, int n, vector<vector<int>> &mat) // We are moving collumn wise, and for every col, we are checking for every row indices.
{
    if (col == n)
    {
        for (auto matRow : mat)
        {
            for (auto ele : matRow)
                cout << ele << " ";
            cout << endl;
        }
        return true; // For printing only one solution.
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, mat))
        {
            mat[row][col] = 1;
            if (NQueen(col + 1, n, mat))
                return true;
            mat[row][col] = 0;
        }
    }
    return false;
}

void solveNQueen()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));
    NQueen(0, n, mat);
}

int32_t main()
{
    // vector<int> arr = {1, 2, 3, 4};
    // int k = 2, sum = 0;
    // int n = sizeof(arr) / sizeof(arr[0]);
    // vector<int> v;
    // printSubSeq(arr, 0, k, sum, v);
    // printOnlyOneSubSeq(arr, 0, k, sum, v);

    /*  N-Queen Problem:
    */

    solveNQueen();

    return 0;
}