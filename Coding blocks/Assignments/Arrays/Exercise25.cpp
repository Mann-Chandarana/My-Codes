////////////////// Calculate the sum of circular array

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, *arr, Q,adder,sum=0,temp;
    cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> Q;

    while (Q--)
    {
        cin >> temp;
        int array[n] = {0};

        for (int i = 0; i < n; i++)
        {
            adder = (n - temp + i) % n;
            array[i] = arr[i] + arr[adder];
        }

        for (int i = 0; i < n; i++)
        {
            arr[i] = array[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    cout << (sum) % (int(pow(10, 9)) + 7);

    delete (arr);

    return 0;
}