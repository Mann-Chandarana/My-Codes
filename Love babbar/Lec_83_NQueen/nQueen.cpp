#include <bits/stdc++.h>
using namespace std;

// Question: https://www.codingninjas.com/codestudio/problems/the-n-queens-puzzle_981286?topList=love-babbar-dsa-sheet-problems&leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

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

bool isSafe(vvi &board, int row, int col, int n, vi &rowVec, vi &ULDiag, vi &LLDiag)
{
    if ((rowVec[row] == 1) or (ULDiag[col - row + n - 1] == 1) or (LLDiag[col + row] == 1))
        return false;
    return true;
}

void printSolutions(vvi &board, vvi &ans, int col, int n, vi &rowVec, vi &ULDiag, vi &LLDiag)
{
    if (col == n)
    {
        // vi tempAns;
        // for (int i = 0; i < n; i++)
        //     for (int j = 0; j < n; j++)
        //         tempAns.push_back(board[i][j]);
        // ans.push_back(tempAns);

        for (auto row : board)
        {
            for (auto ele : row)
                cout << ele << " ";
            cout << endl;
        }
        cout << endl;

        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(board, row, col, n, rowVec, ULDiag, LLDiag))
        {
            board[row][col] = 1;
            rowVec[row] = 1;
            ULDiag[col - row + n - 1] = 1;
            LLDiag[row + col] = 1;

            printSolutions(board, ans, col + 1, n, rowVec, ULDiag, LLDiag);

            board[row][col] = 0;
            rowVec[row] = 0;
            ULDiag[col - row + n - 1] = 0;
            LLDiag[row + col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    vvi board(n, vector<int>(n, 0));
    // 0 indicates free block

    vvi ans;

    if (n == 2 or n == 3)
        return ans;

    vi rowVec(n, 0);
    vi ULDiag(2 * n - 1, 0);
    vi LLDiag(2 * n - 1, 0);

    printSolutions(board, ans, 0, n, rowVec, ULDiag, LLDiag);

    return ans;
}

int main()
{
    int n;
    cin >> n;
    vvi ans;

    vi row(n, 0);
    vi BLDiag(2 * n - 2, 0);
    vi ULDiag(2 * n - 2, 0);

    ans = nQueens(n);

    // for (auto row : ans)
    // {
    //     for (auto ele : row)
    //         cout << ele << " ";
    //     cout << endl;
    // }

    return 0;
}