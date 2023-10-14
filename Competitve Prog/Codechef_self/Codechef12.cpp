#include <iostream>
#include <climits>
using namespace std;
////////////////////////////////////////////////////
int GCD(int n1, int n2)
{
    int hcf;
    if (n2 > n1)
    {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    for (int i = 1; i <= n2; i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            hcf = i;
        }
    }
    return hcf;
}
////////////////////////////////////////////////////
int main()
{
    int t, n, m, hcf;
    cin >> t;
    while (t--)
    {
        cin >> n;

        int arr[n], a[n], ai[n],ans[t];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        //////////////////////////////////////////////
        for (int i = 0; i < n; i++)
        {
            m = n;
            for (int k = 0; k < n; k++)
            {
                a[k] = arr[k];
            }
            for (int j = i; j < n - 1; j++)
            {
                a[j] = a[j + 1];
            }
            m--;
            if (m == 1)
            {
                hcf = a[0];
            }

            for (int i = 1; i < m; i++)
            {
                hcf = a[0];
                
                if ((i + 1) != m)
                {
                    hcf = GCD(hcf, a[i]);
                    if (hcf == 1)
                    {
                        break;
                    }
                }
            }
            ai[i] = hcf;
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << ai[i] << endl;
        // }

        ///////////////////////////////////////////////
        bool check = 1;
        for (int i = 0; i < n - 1; i++)
        {
            if (ai[0] != ai[i + 1])
            {
                check = 0;
            }
        }
        int sum = 0;
        if (check == 1)
        {
            int mx = INT_MIN, mn = INT_MAX;
            for (int i = 0; i < n; i++)
            {
                mx = max(mx, arr[i]);
            }
            for (int i = 0; i < n; i++)
            {
                mn = min(mn, arr[i]);
            }
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == mx)
                {
                    arr[i] = mn;
                    break;
                }
            }
            for (int i = 0; i < n; i++)
            {
                sum = sum + (arr[i] / mn);
            }
            cout << sum << endl;
        }
        else
        {
            int mx = INT_MIN;
            for (int i = 0; i < n; i++)
            {
                mx = max(mx, ai[i]);
            }
            for (int i = 0; i < n; i++)
            {
                if (ai[i] == mx)
                {
                    arr[i] = mx;
                    break;
                }
            }
            for (int i = 0; i < n; i++)
            {
                sum = sum + (arr[i] / mx);
            }
            cout << sum << endl;
        }
    }

    return 0;
}