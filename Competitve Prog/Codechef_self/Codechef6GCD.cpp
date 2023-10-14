#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int hcf;
    int temp = min(a, b);
    for (int i = 1; i <= temp; i++)
    {
        if ((a % i == 0) && (b % i == 0))
        {
            hcf = i;
        }
    }
    return hcf;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int size;
        cin >> size;
        int arr[size];
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        int l = gcd(arr[0], arr[1]);
        for (int i = 2; i < size; i++)
        {
            l = gcd(l, arr[i]);
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] / l << " ";
        }
        cout << endl;
    }

    return 0;
}