/////////////////// Nth triangle recurrsion

#include <iostream>
using namespace std;

int rec_func(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return (n + rec_func(n - 1));
}

int main()
{
    int n;
    cin >> n;

    cout << rec_func(n) << endl;
    return 0;
}