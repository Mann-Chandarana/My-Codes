#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a[4] = {1, 2, 3, 4};

    for (int i = 0; i < 4; i++)
    {
        cout << setw(2) << a[i] << "  ";
    }
    cout << "\n" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << setw(2) << 2 * a[i] << "  ";
    }
    cout << "\n" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << setw(2) << 3 * a[i] << "  ";
    }
    cout << "\n" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << setw(2) << 4 * a[i] << "  ";
    }

    return 0;
}
