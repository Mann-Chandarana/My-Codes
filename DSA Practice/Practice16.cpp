#include <iostream>
using namespace std;

int main()
{
    int n1, n2, n3, h1 = 0, h2 = 0, h3 = 0;
    cin >> n1 >> n2 >> n3;
    int arr1[n1], arr2[n2], arr3[n3];
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
        h1 += arr1[i];
    }
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
        h2 += arr2[i];
    }
    for (int i = 0; i < n3; i++)
    {
        cin >> arr3[i];
        h3 += arr3[i];
    }
    int i = 0, j = 0, k = 0;
    while (1)
    {
        if ((h1 == h2 && h2 == h3) || h1 == 0 || h2 == 0 || h3 == 0)
        {
            break;
        }
        else if (h1 == max(max(h1, h2), h3))
        {
            h1 -= arr1[i++];
            //cout << h1 << endl;
        }
        else if (h2 == max(max(h1, h2), h3))
        {
            h2 -= arr2[j++];
            //cout << h2 << endl;
        }
        else if (h3 == max(max(h1, h2), h3))
        {
            h3 -= arr3[k++];
            //cout << h3 << endl;
        }
    }
    if (h1 == 0 || h2 == 0 || h3 == 0)
    {
        cout << "0" << endl;
    }
    else
    {
        cout << h1 << endl;
    }

    return 0;
}