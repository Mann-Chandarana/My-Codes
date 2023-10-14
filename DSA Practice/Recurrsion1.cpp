#include <iostream>
#include <vector>
using namespace std;
//////////////////////////////// NQueen Problem
bool NQueen(int col, int n, vector<vector<int>> &mat)
{
    if (col == n)
    {
        for (auto matrow : mat)
        {
            for (auto ele : matrow)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
        return true;
    }
    for (int row = 0; row < n; row++)
    {
        if (issafe(row, col, mat))
        {
            mat[row][col] = 1;
            if (NQueen(col + 1, n, mat))
            {
                return true;
            }
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
int main()
{
    solveNQueen();
    return 0;
}