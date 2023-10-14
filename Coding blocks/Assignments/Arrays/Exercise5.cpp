//Pattern triangle

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int row = 1; row <= n; row++)
    {
        int column;
        for (column = 1; column <= n - row; column++)
        {
            cout << "\t";
        }
        int var = row;
        for (; column <= n; column++)
        {
            cout << var << "\t";
            var++;
        }
        var -= 2;
        for (; column <= n + row - 1; column++)
        {
            cout << var << "\t";
            var--;
        }

        cout << endl;
    }

    return 0;
}