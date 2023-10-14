#include <iostream>
using namespace std;

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        int cnt = 0;
        string str;
        cin >> n;
        cin >> str;
        for (int i = 0; i < n-1; i++)
        {
            if (str[i] == '1' && str[i+1] == '0')
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }

    return 0;
}