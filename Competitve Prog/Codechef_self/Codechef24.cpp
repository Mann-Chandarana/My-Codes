#include <iostream>
using namespace std;

int main()
{
    int t, n, count_one = 0, count_zero = 0, answer;
    char *arr;
    cin >> t;

    while (t--)
    {
        answer = 0;
        cin >> n;
        arr = new char[n];
        int i;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (i = 0; i < n; i++)
        {
            if (arr[i] == '1')
            {
                count_one++;
            }
            else
            {
                count_zero++;
            }
        }

        answer = max(0,(min(count_one, count_zero) - 1));
        cout << answer << endl;
    }

    return 0;
}