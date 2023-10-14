#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Upper half
    for (int row = 1; row < n; row++)
    {
        if (row == 1)
        {
            for (int column = 0; column < (2 * n - 1); column++)
            {
                cout << "*";
            }
            cout << endl;
        }

        for (int column = 0; column < (n - row); column++)
        {
            cout << "*";
        }
        for (int column = 0; column < (2 * row - 1); column++)
        {
            cout << " ";
        }
        for (int column = 0; column < (n - row); column++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // lower half
    for (int row = 1; row < n; row++)
    {
        for (int column = 0; column < (row + 1); column++)
        {
            cout << "*";
        }
        for (int column = 0; column < (2 * (n - (row + 1)) - 1); column++)
        {
            cout << " ";
        }
        for (int column = 0; column < (row + 1); column++)
        {
            cout << "*";
        }
        cout << endl;
        if (row == n)
        {
            for (int column = 0; column < (2 * n - 1); column++)
            {
                cout << "*";
            }
            cout << endl;
            break;
        }
    }

    return 0;
}