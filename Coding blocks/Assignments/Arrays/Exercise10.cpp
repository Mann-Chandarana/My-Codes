/// Pattern mountain

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int row = 0; row < n; row++)
    {
        int value = 1;
        for (int col = 0; col < row + 1; col++)
        {
            cout << value << " ";
            value++;
        }

        for (int col = 0; col < 2 * (n - row) - 3; col++)
        {
            cout << "  ";
        }

        if (row == n - 1)
        {
            for (int col = n - 1; col > 0; col--)
            {
                cout << col << " ";
            }
            break;
        }

        value--;
        for (int col = 0; col < row + 1; col++)
        {
            cout << value << " ";
            value--;
        }
        cout << endl;
    }

    return 0;
}