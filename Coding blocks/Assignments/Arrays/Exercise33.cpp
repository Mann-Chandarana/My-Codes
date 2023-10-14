////////////////// Spiral clockwise print array

#include <iostream>
using namespace std;

/*
1) sr
2) ec
3) er
4) sc 
*/

void spiral_print(int **arr, int m, int n)
{
    int sc = 0, sr = 0, ec = n - 1, er = m - 1;

    while (sc <= ec && sr <= er)
    {

        for (int i = sc; i <= ec; i++)
        {
            cout << arr[sr][i] << ", ";
        }
        sr++;

        if (sc < ec)
        {
            for (int i = sr; i <= er; i++)
            {
                cout << arr[i][ec] << ", ";
            }
            ec--;
        }

        if (sr < er)
        {
            for (int i = ec; i >= sc; i--)
            {
                cout << arr[er][i] << ", ";
            }
            er--;
        }

        for (int i = er; i >= sr; i--)
        {
            cout << arr[i][sc] << ", ";
        }
        sc++;
    }
    cout << "END" << endl;
}

int main()
{
    int row, col;
    cin >> row >> col;

    int **arr = new int *[row];

    for (int i = 0; i < row; i++)
    {
        arr[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> arr[i][j];
        }
    }

    spiral_print(arr, row, col);

    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}