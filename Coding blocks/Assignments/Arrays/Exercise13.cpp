//// Hollow diamond pattern

#include <iostream>
using namespace std;

int main()
{
    int n, Size;
    cin >> n;

    if (n > 3)
    {
        Size = (n - 3);
    }
    else
    {
        Size = (n + 1) / 2;
    }

    // Upper half
    for (int row = 1; row <= Size; row++)
    {
        for (int col = 1; col <= n - row - 1; col++)
        {
            if (row == 1 && col == n - row - 1)
            {
                break;
            }

            cout << "*"
                 << "\t";
        }
        for (int col = 1; col <= 2 * (row - 1) - 1; col++)
        {
            cout << "\t";
        }

        for (int col = 1; col <= n - row - 1; col++)
        {
            cout << "*"
                 << "\t";
        }
        cout << endl;
    }

    // lower half
    if (n > 3)
    {
        Size = (n - 2);
    }
    else
    {
        Size = n / 2;
    }

    for (int row = Size; row > 0; row--)
    {
        for (int col = 1; col <= n - row - 1; col++)
        {
            if (row == 1 && col == n - row - 1)
            {
                break;
            }

            cout << "*"
                 << "\t";
        }
        for (int col = 1; col <= 2 * (row - 1) - 1; col++)
        {
            cout << "\t";
        }

        for (int col = 1; col <= n - row - 1; col++)
        {
            cout << "*"
                 << "\t";
        }
        cout << endl;
    }

    return 0;
}