///////////// Duplicate character fromatting

#include <iostream>
using namespace std;

void consecutive(char *s, int i, int n)
{
    ////////// Base case
    if (s[i] == '\0')
    {
        return;
    }

    ////////// recursive relation
    if (i + 1 < n && s[i] == s[i + 1])
    {
        int j = i + 2;
        while (j < n)
        {
            j++;
        }
        while (j >= i)
        {
            s[j + 1] = s[j];
            j--;
        }
        n += 1;
        s[i + 1] = '*';
        consecutive(s, i + 2, n);
    }
    else
    {
        consecutive(s, i + 1, n);
    }
}

int main()
{
    char s[100];
    cin >> s;
    int n = 0;
    for (int i = 0; i < 100; i++)
    {
        if (s[i] == '\0')
        {
            break;
        }
        n++;
    }

    consecutive(s, 0, n);
    cout << s << endl;

    return 0;
}