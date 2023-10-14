////////////// Maximum frequency

#include <iostream>
#include <climits>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int arr[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        arr[(s[i] - 'a')]++;
    }

    int maxi = 0;
    int index = 0;

    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
        {
            if (arr[i] > maxi)
            {
                maxi = arr[i];
                index = i;
            }
        }
    }
    cout << char('a' + index) << endl;

    return 0;
}