////////////////// Suduko solver

#include <iostream>
#include <cmath>
using namespace std;

bool isValid(int **arr, int x, int y, int number, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[x][i] == number)
        {
            return false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i][y] == number)
        {
            return false;
        }
    }

    int ro = sqrt(n);
    int smx = x / ro * ro;
    int smy = y / ro * ro;

    for (int i = 0; i < ro; i++)
    {
        for (int j = 0; j < ro; j++)
        {
            if (arr[smx + i][smy + j] == number)
            {
                return false;
            }
        }
    }
    return true;
}

void solveSuduko(int **arr, int x, int y, int n)
{
    if (x == n)
    {
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    int ni, nj;
    if (y == n - 1)
    {
        ni = x + 1;
        nj = 0;
    }
    else
    {
        ni = x;
        nj = y + 1;
    }

    if (arr[x][y] != 0)
    {
        solveSuduko(arr, ni, nj, n);
    }
    else
    {
        for (int num = 1; num <= 9; num++)
        {
            if (isValid(arr, x, y, num, n))
            {
                arr[x][y] = num;
                solveSuduko(arr, ni, nj, n);
                arr[x][y] = 0;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int **arr = new int *[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    solveSuduko(arr, 0, 0, n);
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}