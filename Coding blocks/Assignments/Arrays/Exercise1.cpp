#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int row = 1; row <= n; row++)
    {
        if (row == 1)
        {
            for (int j = 0; j < n - row; j++)
            {
                cout << " ";
            }
            for (int j = 0; j < n; j++)
            {
                cout << "*";
            }
            cout << endl;
        }
        else if (row == n)
        {
            for (int i = 0; i < n; i++)
            {
                cout << "*";
            }
            cout << endl;
        }
        else
        {
            for (int j = 0; j < n - row; j++)
            {
                cout << " ";
            }
            cout << "*";
            for (int i = 0; i < n-2; i++)
            {
                cout << " ";
            }
            cout << "*";
            for (int i = 0; i < row - 1; i++)
            {
                cout << " ";
            }
            cout << endl;
        }
    }

    return 0;
}