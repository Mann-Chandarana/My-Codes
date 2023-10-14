////////////// Alex goes shopping

#include <iostream>
using namespace std;

int main()
{
    int n, *arr, q, Rupees, items;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> q;

    int count;
    while (q--)
    {
        cin >> Rupees >> items;
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (Rupees % arr[i] == 0 ||Rupees % arr[i] == arr[i])
            {
                count++;
            }
        }

        if (count >= items)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    delete (arr);

    return 0;
}