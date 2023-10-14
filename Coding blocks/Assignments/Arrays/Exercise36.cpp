///////////////// Transpose of a matrix

#include <iostream>
using namespace std;

void Transpose_matrix(int **a, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i)
            {
                swap(a[i][j], a[j][i]);
            }
        }
    }
    cout << endl;
}

int main()
{
    int N;
    cin >> N;

    int **arr = new int *[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = new int[N];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arr[i][j];
        }
    }

    Transpose_matrix(arr, N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}