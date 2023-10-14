/////////////// Make Palindrome (Important to read question)

#include <iostream>
using namespace std;

bool isPalindrome(string str)
{
    int start = 0;
    int end = str.length() - 1;

    while (start <= end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    int t, n;
    cin >> t;

    while (t--)
    {
        cin >> n;
        string str;
        cin >> str;

        if (isPalindrome(str))
        {
            cout << str << endl;
        }
        else
        {
            int nz = 0, no = 0;
            string ans = "";
            for (int i = 0; i < n; i++)
            {
                if (str[i] == '0')
                {
                    nz++;
                }
                else
                {
                    no++;
                }
            }
            if (nz >= no)
            {
                for (int i = 0; i < nz; i++)
                {
                    ans += '0';
                }
            }
            else
            {
                for (int i = 0; i < no; i++)
                {
                    ans += '1';
                }
            }
            cout << ans << endl;
        }
    }

    return 0;
}