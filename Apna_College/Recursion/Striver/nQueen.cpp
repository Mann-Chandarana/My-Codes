#include "bits/stdc++.h"
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &mat)
{
    // For upper-left diagonal. row - 1 and col - 1.
    for (int i = row, j = col; i >= 0 and j >= 0; i--, j--)
        if (mat[i][j] == 1)
            return false;

    // For left. row and col - 1.
    for (int i = row, j = col; i >= 0 and j >= 0; j--)
        if (mat[i][j] == 1)
            return false;

    // For bottom-left diagonal. row + 1 and col - 1.
    for (int i = row, j = col; i < mat.size() and j >= 0; i++, j--)
        if (mat[i][j] == 1)
            return false;

    return true;
}

bool isSafe2(int row, int col, vector<vector<int>> &mat, vector<int> &rowArr, vector<int> &BLDiag, vector<int> &ULDiag)
// Better version of isSafe().
{
    // for (int i = row, j = col; i >= 0 and j >= 0; i--, j--)
    //     if (mat[i][j] == 1)
    //         return false;
    if (ULDiag[col - row + mat.size()] == 1)
        return false;

    // for (int i = row, j = col; i >= 0 and j >= 0; j--)
    //     if (mat[i][j] == 1)
    //         return false;
    if (rowArr[row] == 1)
        return false;

    // for (int i = row, j = col; i < mat.size() and j >= 0; i++, j--)
    //     if (mat[i][j] == 1)
    //         return false;
    if (BLDiag[row + col] == 1)
        return false;

    return true;
}

// For bottom-left Diagonal
/*
    idx:       0   1   2   3

        0      0   1   2   3
        1      1   2   3   4
        2      2   3   4   5
        3      3   4   5   6
        Pattern: All diagonals have same values.
        Create a vector of size (n - 1)*2. // Here n=4. size of BLDiag = 6 which is (4 - 1) + (4 - 1) = 3 + 3.
*/

// For Upper-left Diagonal:
/*
    Do col - row + n at every index in the matrix. Adding n is to bring the index to a positive value.
    Then all the upper-left Daigonal will have same val.
    idx:       0    1    2   3

        0      0    1    2   3
        1     -1   -0    1   2
        2     -2   -1    0   1
        3     -3   -2   -1   0
*/

bool NQueen(int col, int n, vector<vector<int>> &mat, vector<int> &rowArr, vector<int> &BLDiag, vector<int> &ULDiag)
{
    if (col == n)
    {
        for (auto matRow : mat)
        {
            for (auto ele : matRow)
                cout << ele << " ";
            cout << endl;
        }
        return true;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe2(row, col, mat, rowArr, BLDiag, ULDiag))
        {
            mat[row][col] = 1;         // For placing the queen at that position in the original matrix.
            rowArr[row] = 1;           // For checking in the left side (If there is already a queen in that row at previous cols).
            BLDiag[col + row] = 1;     // For checking at Bottom-Left Diagonal.
            ULDiag[col - row + n] = 1; // For checking at Upper-Left Diagonal.
            if (NQueen(col + 1, n, mat, rowArr, BLDiag, ULDiag) == true)
                return true; // To end, because we have already got one answer, and there could be more than one ways, but we want only one way.
            rowArr[row] = 0;
            BLDiag[col + row] = 0;
            mat[row][col] = 0;
            ULDiag[col - row + n] = 0;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n, 0));

    vector<int> row(n, 0);
    vector<int> BLDiag(2 * n - 2, 0);
    vector<int> ULDiag(2 * n - 1, 0);

    if (NQueen(0, n, mat, row, BLDiag, ULDiag) == false) // For n = 2 and n = 3.
        cout << "Cannot Create!" << endl;

    return 0;
}