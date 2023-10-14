/// Pattern Inverted hour glass

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // Upper half
    for (int row = 0; row <= n; row++)
    {
        int val = n;
        for (int col = 0; col < row + 1; col++)
        {
            cout << val << " ";
            val--;
        }

        for (int col = 0; col < (2 * (n - row) - 1); col++)
        {
            cout << "  ";
        }

        if (row == n)
        {
            for (int col = 1; col < row + 1; col++)
            {
                cout << col << " ";
            }
            cout << endl;
            break;
        }

        val++;
        for (int col = 0; col < row + 1; col++)
        {
            cout << val << " ";
            val++;
        }
        cout << endl;
    }

    // Lower half
    for (int row = 1; row <= n; row++)
    {
        int value = n;

        for (int col = 1; col <= (n - row + 1); col++)
        {
            cout << value << " ";
            value--;
        }

        for (int col = 1; col <= (2 * row - 1); col++)
        {
            cout << "  ";
        }

        value++;
        for (int col = 1; col <= (n - row + 1); col++)
        {
            cout << value << " ";
            value++;
        }
        cout << endl;
    }

    return 0;
}                  