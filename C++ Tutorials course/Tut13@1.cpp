#include <iostream>
#include <string>
#include <algorithm> //to use sort function
using namespace std;

// int main()
// {
//     string str = "wnebf3hebrfh";
//     // Convert into upper case
//     for (int i = 0; i < str.size(); i++)
//     {
//         if (str[i] >= 'a' && str[i] <= 'z')
//         {
//             str[i] -= 32;
//         }
//     }
//     cout << str;
//     cout<<"\n";
//     // Convert into lower case
//     for (int i = 0; i < str.size(); i++)
//     {
//         if (str[i] >= 'A' && str[i] <= 'Z')
//         {
//             str[i] += 32;
//         }
//     }
//     cout << str;

//     return 0;
// }

////// Another method
// int main()
// {
//     string str = "wnebf3hebrfh";
//     transform(str.begin(), str.end(), str.begin(), ::toupper);
//     cout << str << endl;
//     transform(str.begin(), str.end(), str.begin(), ::tolower);
//     cout << str << endl;
//     return 0;
// }

////// Form the biggest number from the numeric string

// int main()
// {
//     string s = "498723659";
//     sort(s.begin(), s.end(), greater<int>); // greater<int> - to sort in reverse order
//     cout << s << endl;
//     return 0;
// }

///// Most number of time character has appeared
int main()
{
    string s = "fbewfbfewirber";
    int freq[26];
    for (int i = 0; i < 26; i++)
    {
        freq[i] = 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }
    char ans = 'a';
    int maxF = 0;

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > maxF)
        {
            maxF = freq[i];
            ans = i + 'a';
        }
    }
    cout << maxF << " " << ans << endl;
    return 0;
}