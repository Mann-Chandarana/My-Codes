#include <iostream>
using namespace std;

int main()
{
    int n, temp = 1, prev = 0, sum = 0;
    cin >> n;
    for (int row = 0; row < n; row++)
    {
        if (row == 0)
        {
            cout << "0" << endl;
            continue;
        }
        for (int column = 0; column < (row + 1); column++)
        {
            if (row == 1 && column == 0)
            {
                cout << temp << "\t";
                continue;
            }
            sum = temp + prev;
            cout << sum << "\t";
            prev = temp;
            temp = sum;
        }
        cout << endl;
    }

    return 0;
}