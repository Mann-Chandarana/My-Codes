#include <iostream>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int *a = new int[n];

    int no;
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> no;
        a[i] = no;
        res = res ^ no;
    }
    // xor = a^b;
    int temp = res;
    int pos = 0;
    while ((temp & 1) != 1)
    {
        pos++;
        temp = temp >> 1;
    }

    int mask = (1 << pos);

    int x = 0;
    int y = 0;

    for (int i = 0; i < n; i++)
    {
        if ((a[i] & mask) > 0)
        {
            x = x ^ a[i];
        }
    }
    y = res ^ x;

    cout << min(x, y) << " " << max(x, y) << endl;
    delete[] a;
    return 0;
}