////////// Floodfill problem using dfs + recurrsion

#include <bits/stdc++.h>
using namespace std;

int R, C;
// W,N,E,S
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

// ch is the character to be replaced
// color is the character to be added

void floodFIll(char mat[][50], int i, int j, char ch, char color)
{
    //// Base case - Matrix bonds
    if (i < 0 || j < 0 || i >= R || j >= C)
    {
        return;
    }

    // Figure Boundary Condition
    if (mat[i][j] != ch)
    {
        return;
    }

    // Recursive Call
    mat[i][j] = color;

    for (int k = 0; k < 4; k++)
    {
        floodFIll(mat, i + dx[k], j + dy[k], ch, color);
    }
}

int main()
{
    cin >> R >> C;
    char input[15][50];

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> input[i][j];
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << input[i][j];
        }
    }

    floodFIll(input, 8, 13,'.','r');

    return 0;
}