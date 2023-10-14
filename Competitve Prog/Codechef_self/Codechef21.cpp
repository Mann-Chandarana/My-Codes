#include <iostream>
#include <climits>
using namespace std;

bool isEquals(int *a)                    
{
    int length = sizeof(a);
    bool isTrue = true;
    for (int i = 0; i < length; i++)
    {
        if (a[i] != a[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        int No_of_Players;
        cin >> No_of_Players;
        int *arr = new int[No_of_Players];

        for (int i = 0; i < No_of_Players; i++)
        {
            cin >> arr[i];
        }

        int sum = 0;
        int minimum = INT_MAX;

        if (isEquals(arr))
        {
            for (int i = 0; i < (No_of_Players - 1); i++)
            {
                sum += arr[i];
            }
        }
        else
        {
            for (int i = 0; i < No_of_Players; i++)
            {
                minimum = min(minimum, arr[i]);
            }

            for (int i = 0; i < No_of_Players; i++)
            {
                sum += arr[i];
            }
            sum -= minimum;
        }
        cout << sum << endl;
    }

    return 0;
}