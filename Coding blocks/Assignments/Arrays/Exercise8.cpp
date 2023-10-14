/// Pattern hour glass

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    /// Upper half
    for (int row = 0; row <= n; row++)
    {
        for (int col = 0; col < row; col++)
        {
            cout << "  ";
        }

        for (int col = (n - row); col >= 0; col--)
        {
            cout << col << " ";
        }
        int val = 1;
        for (int col = val; col <= n - row; col++)
        {
            cout << val << " ";
            val++;
        }
        cout << endl;
    }

    /// Lower half

    for (int row = n; row > 0; row--)
    {
        for (int col = 0; col < row - 1; col++)
        {
            cout << "  ";
        }

        for (int col = (n - row + 1); col >= 0; col--)
        {
            cout << col << " ";
        }
        int val = 1;
        for (int col = val; col <= n - row + 1; col++)
        {
            cout << val << " ";
            val++;
        }
        cout << endl;
    }

    return 0;
}