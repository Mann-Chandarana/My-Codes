#include <iostream>
using namespace std;

//////////////////////////////////////////////////////////////////////
// 1)- Generate substring
// void subseq(string s, string ans)
// {
//     if (s.length() == 0)
//     {
//         cout << ans << endl;
//         return;
//     }

//     char ch = s[0];
//     string ros = s.substr(1);

//     subseq(ros, ans);
//     subseq(ros, ans + ch);
// }
// int main()
// {
//     subseq("ABC", "");
//     return 0;
// }

//////////////////////////////////////////////////////////////////////
// 2)- Generate substring with ascii code
// void subseq(string s, string ans)
// {
//     if (s.length() == 0)
//     {
//         cout << ans << endl;
//         return;
//     }

//     char ch = s[0];
//     int code = ch;
//     string ros = s.substr(1);

//     subseq(ros, ans);
//     subseq(ros, ans + ch);
//     subseq(ros,ans+to_string(code));
// }

// int main()
// {
//     subseq("AB","");
//     return 0;
// }

//////////////////////////////////////////////////////////////////////
//3) - Generate possible pairs

string keyArray[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void keypad(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string code = keyArray[ch - '0'];
    string ros = s.substr(1);
    for (int i = 0; i < code.length(); i++)
    {
        keypad(ros, ans + code[i]);
    }
}
int main(int argc, char const *argv[])
{
    keypad("23", "");
    return 0;
}
