///////// Find greater element

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool *is_marked = new bool[n]{0};

    for (int i = 0; i < n; i++)
    {
        bool is_bigger = false;
        int count = 0;
        for (int j = i + 1; count != n-1; j = (j + 1) % (n-1))
        {
            if ((arr[i] < arr[j]) && is_marked[j] == 0)
            {
                is_bigger = true;
                cout << arr[j] << " ";
                is_marked[j] = 1;
                break;
            }
            count++;
        }
        if (!is_bigger)
        {
            cout << -1 << " ";
        }
    }

    return 0;
}