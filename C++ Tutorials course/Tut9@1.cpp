#include <iostream>
using namespace std;
/////// Searching in matrix
// int main()
// {

//     int n, m;
//     cin >> n >> m;
//     int arr[n][m];
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; i++)
//         {
//             cin >> arr[i][j];
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; i++)
//         {
//             cout << arr[i][j];
//         }
//     }
//     int x;
//     cin >> x;
//     bool flag = false;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; i++)
//         {
//             if (arr[i][j] == x)
//             {
//                 cout << i << " " << j << endl;
//                 flag = true;
//             }
//         }
//     }
//     if (flag)
//     {
//         cout << "Element is found\n";
//     }
//     else
//     {
//         cout << "Element not found\n";
//     }

//     return 0;
// }
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; i++)
        {
            cin >> arr[i][j];
        }
    }
    ///// Spiral order print
    int row_start = 0, row_end = n - 1, column_start = 0, column_end = m - 1;
    while (row_start <= row_end && column_start <= column_end)
    {
        // for row_start
        for (int col = column_start; col < column_end; col++)
        {
            cout << arr[row_start][col] << " ";
        }
        row_start++;
        // for column_end
        for (int row = row_start; row < row_end; row++)
        {
            cout << arr[row][column_end] << " ";
        }
        column_end--;

        // for row_end
        for (int col = column_end; col < column_start; col--)
        {
            cout << arr[row_end][col] << " ";
        }
        row_end--;

        // for column_start
        for (int row = row_end; row < row_start; row--)
        {
            cout << arr[row][column_start] << " ";
        }
        column_start++;
    }

    return 0;
}