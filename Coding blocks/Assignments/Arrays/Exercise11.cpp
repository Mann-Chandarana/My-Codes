/// Pattern rhombus

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    /// Upper half
    for (int row = 1; row <= n; row++)
    {
        for (int col = 1; col <= (n - row); col++)
        {
            cout << "\t";
        }
        int val = row;

        for (int col = 1; col <= row; col++)
        {
            cout << val << "\t";
            val++;
        }
        val -= 2;
        for (int col = n; col < (n + row - 1); col++)
        {
            cout << val << "\t";
            val--;
        }
        cout << endl;
    }

    /// Lower half

    for (int row = (n - 1); row > 0; row--)
    {
        for (int col = 1; col <= (n - row); col++)
        {
            cout << "\t";
        }

        int val = row;

        for (int col = 1; col <= row; col++)
        {
            cout << val << "\t";
            val++;
        }
        val -= 2;
        for (int col = n; col < (n + row - 1); col++)
        {
            cout << val << "\t";
            val--;
        }
        cout << endl;
    }

    return 0;
}