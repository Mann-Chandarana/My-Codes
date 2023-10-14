///////////////////// Class assignment

#include <bits/stdc++.h>
using namespace std;

int calculate_numbers(int n)
{
    if (n == 1)
    {
        return 2;
    }
    else if (n == 2)
    {
        return 3;
    }
    else
    {
        return calculate_numbers(n - 1) + calculate_numbers(n - 2);
    }
}

int main()
{

    int t;
    cin >> t;
    int i = 1;
    while (t--)
    {
        int n;
        cin >> n;
        cout << "#" << i++ << " : " << calculate_numbers(n) << endl;
    }
}