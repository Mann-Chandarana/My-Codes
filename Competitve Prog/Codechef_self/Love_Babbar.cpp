#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

string decimalToBinary(int n)
{

    int binaryNum[1000];

    int i = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    string bin;
    for (int j = i-1; j>=0; j--)
    {
        bin.push_back(binaryNum[j]+'0');
    }
    
    return bin;
}

int multipleLength(vector<int> &a, int n)
{
    long long int mul = 1;
    for (int i = 0; i < n; i++)
    {
        mul *= a[i];
    }
    cout << mul << endl;
    string bin = decimalToBinary(mul);

    return (bin.length());
}

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << multipleLength(arr, n) << endl;
    }

    return 0;
}