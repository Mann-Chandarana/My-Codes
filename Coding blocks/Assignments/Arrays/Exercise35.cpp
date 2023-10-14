//////////////////// Rotate array

#include <iostream>
using namespace std;

void rotate_array(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        int x = 0, y = n - 1;
        while (x < y)
        {
            swap(arr[i][x], arr[i][y]);
            x++;
            y--;
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j)
            {
                swap(arr[i][j], arr[j][i]);
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

    rotate_array(arr, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}