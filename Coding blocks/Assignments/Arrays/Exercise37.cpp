/////////////////// Matrix search

#include <iostream>
using namespace std;

int main()
{
    int m, n, o, i, j, arr[100][100];
    bool ans;
    cin >> m >> n;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cin >> o;
    i = 0, j = n - 1;
    ans = false;
    while (i < m && j >= 0)
    {
        if (o == arr[i][j])
        {
            ans = true;
            break;
        }
        else if (o < arr[i][j])
        {
            j--;
        }
        else if (o > arr[i][j])
        {
            i++;
        }
    }
    cout << ans;
}