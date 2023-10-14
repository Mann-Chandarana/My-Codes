#include <iostream>
using namespace std;

int is_Plaindrome(string s)
{
    cout << s << endl;

    bool is_palindrome = true;
    int leng = s.length();
    if (leng == 1)
    {
        return true;
    }

    for (int i = 0; i < leng / 2; i++)
    {
        if (s[i] != s[leng - i - 1])
        {
            is_palindrome = false;
            return false;
        }
    }
    if (is_palindrome)
    {
        return true;
    }
    return false;
}

int main()
{
    string s;
    cin >> s;

    int count = 0;

    int leng = s.length();

    for (int i = 0; i < leng; i++)
    {
        for (int j = i; j < leng; j++)
        {
            if (is_Plaindrome(s.substr(i, j)))
            {
                count++;
            }
        }
    }
    cout << --count << endl;

    return 0;
}