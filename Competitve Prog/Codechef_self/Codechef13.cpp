#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int movies_no, mx = INT_MIN;
        cin >> movies_no;
        int L[movies_no], R[movies_no], temp, index = 0;
        for (int i = 0; i < movies_no; i++)
        {
            cin >> L[i];
        }
        for (int i = 0; i < movies_no; i++)
        {
            cin >> R[i];
        }
        for (int i = 0; i < movies_no; i++)
        {
            temp = L[i] * R[i];
            if (temp > mx)
            {
                mx = temp;
                index = i;
            }
            else if (temp == mx)
            {
                if (R[index] < R[i])
                {
                    index = i;
                }
            }
        }
        cout << index + 1 << endl;
    }

    return 0;
}