#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    for (int i = x; i < x*y; i++)
    {
        if (i % x == 0 && i % y == 0)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}