///////////////// String - odd and even character

// #include <iostream>
// using namespace std;

// int main()
// {
//     string s;
//     cin >> s;

//     for (int i = 0; i < s.length(); i++)
//     {
//         if (i % 2 == 0)
//         {
//             s[i] = s[i] + '1' - '0';
//         }
//         else
//         {
//             s[i] = s[i] - '1' + '0';
//         }
//     }
//     cout << s << endl;

//     return 0;
// }

/////////////////// String toggle case

// #include <iostream>
// using namespace std;

// int main()
// {
//     string s;
//     cin >> s;

//     int diff = 'A' - 'a';
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (islower(s[i]))
//         {
//             s[i] += diff;
//         }
//         else
//         {
//             s[i] -= diff;
//         }
//     }

//     cout << s << endl;

//     return 0;
// }

////////////////// Different in ascci codes

// #include <iostream>
// using namespace std;

// int main()
// {
//     string s;
//     cin >> s;

//     for (int i = 0; i < s.length(); i++)
//     {
//         if ((i + 1) < s.length())
//         {
//             cout << s[i] << s[i + 1] - s[i];
//         }
//         else
//         {
//             cout << s[i];
//         }
//     }

//     return 0;
// }

////////////////// String compression

// #include <iostream>
// using namespace std;

// int main()
// {
//     string s;
//     cin >> s;

//     int count = 1;

//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == s[i + 1] && i + 1 < s.length())
//         {
//             count++;
//             continue;
//         }
//         else if (count != 1)
//         {
//             cout << s[i] << count;
//             count = 1;
//         }
//         else
//         {
//             cout << s[i];
//         }
//     }

//     return 0;
// }

/////////////////// Remove duplicate 
/////////////////// Imp

#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    char ch;
    ch = s[0];
    bool in_printed = false;
    for (int i = 1; i < s.length(); i++)
    {
        if (i + 1 == s.length())
        {
            if (!in_printed && ch != s[i])
            {
                cout << ch << s[i];
            }
            else
            {
                cout << s[i];
            }
            continue;
        }
        if (ch == s[i] && (i + 1) != s.length())
        {
            continue;
        }
        else
        {
            cout << ch;
            in_printed = true;
            ch = s[i];
            in_printed = false;
        }
    }

    return 0;
}