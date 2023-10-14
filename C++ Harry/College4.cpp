#include <iostream>
using namespace std;

int Add(int *x, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + x[i];
    }
    return sum;
}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int z = Add(a, 10);
    cout << z;

    return 0;
}
