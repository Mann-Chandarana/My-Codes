///////////////// Diagonal Traversal

#include <iostream>
using namespace std;

int main()
{
    int M, N;
    cin >> M >> N;

    int arr[M][N];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    int row = 0, col = 0;
    bool up = false, down = true;
    int maxi = max(M, N);
    for (int i = 0; i < maxi * 2 - 1; i++)
    {
        if (row == 0 && col == 0)
        {
            cout << arr[row][col] << " ";
            if (++col <= N - 1)
            {
            }
            else
            {
                row++;
                col--;
            }

            continue;
        }

        /////////////////////// For 'UP'
        if (up == true)
        {
            while (row >= 0 && row <= M - 1 && col >= 0 && col <= N - 1)
            {
                cout << arr[row][col] << " ";
                row--;
                col++;
            }

            row++;
            col--;
        }
        ////////////////////////// For 'Down'
        else if (down == true)
        {
            while (row >= 0 && row <= M - 1 && col >= 0 && col <= N - 1)
            {
                cout << arr[row][col] << " ";
                row++;
                col--;
            }
            row--;
            col++;
        }
        ////////////////////////////////////////
        if (col > row)
        {
            if (col < N - 1)
            {
                col++;
            }
            else
            {
                row++;
            }
        }
        else if (row > col)
        {
            if (row < M - 1)
            {
                row++;
            }
            else
            {
                col++;
            }
        }
        else if (row == col)
        {
            if (row < M - 1)
            {
                row++;
            }
            else
            {
                col++;
            }
        }

        down = !down;
        up = !up;
    }

    return 0;
}