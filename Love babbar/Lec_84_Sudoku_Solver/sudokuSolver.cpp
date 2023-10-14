#include <bits/stdc++.h>
using namespace std;

// Question: https://www.codingninjas.com/codestudio/problems/sudoku-solver_699919?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

/*
#define getArr(arr, n) for(int i=0;i<n;i++) cin >> arr[i];
#define printArr(arr, n) for(int i=0;i<n;i++)cout << arr[i] << " "; cout << endl;
*/
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<int, int>
#define vvi vector<vector<int>>
#define minhi priority_queue<int, vector<int>, greater<int>>
#define maxhi priority_queue<int>

// TC: O(9^m) where m is no. of empty cells SC: O(1)

bool isSafe(int row, int col, vector<vector<int>> &board, int val)
{
    //     // Row check
    //     for(int r = 0;r<board.size();r++)
    //         if(board[r][col] == val)
    //             return false;

    //     // Col check
    //     for(int c=0;c<board.size();c++)
    //         if(board[row][c] == val)
    //             return false;

    for (int i = 0; i < board.size(); i++)
    {
        if (board[row][i] == val or board[i][col] == val)
            return false;

        // For submatrix
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }

    // Val possible
    return true;
}

bool solve(vector<vector<int>> &board)
{
    int n = board[0].size();

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (board[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (isSafe(row, col, board, val))
                    {
                        board[row][col] = val;
                        if (solve(board))
                            return true;
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n = 9;
    // cin >> n;
    vvi board(n, vi(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    cout << endl;

    if (solve(board) == true)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "Cannot find fill the sudoku board\n";

    return 0;
}