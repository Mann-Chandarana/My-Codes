//////////////////////////////////////////// Question-1
#include <iostream>
using namespace std;
// void reverse_string(string s, int n, int i)
// {
//     if (i == n)
//     {
//         return;
//     }
//     reverse_string(s, n, i + 1);
//     cout << s[i] << " ";
// }

// void reverse(string s)
// {
//     if (s.length() == 0)
//     {
//         return;
//     }
//     string ros = s.substr(1);
//     reverse(ros);
//     cout << s[0];
// }
// int main()
// {
//     string s = "binod";
//     reverse(s);
//     return 0;
// }

//////////////////////////////////////////// Question-2

// void Tower_of_hanoi(int n, char src, char des, char helper)
// {
//     if (n == 0)
//     {
//         return;
//     }

//     Tower_of_hanoi(n - 1, src, helper, des);
//     cout << "Move from " << src << " to " << des << endl;
//     Tower_of_hanoi(n - 1, helper, des, src);
// }
// int main()
// {
//     Tower_of_hanoi(3,'A','C','B');
//     return 0;
// }

//////////////////////////////////////////// Question-3

// string remove_Duplicate(string s)
// {
//     if (s.length() == 0)
//     {
//         return "";
//     }
//     char ch = s[0];
//     string ans = remove_Duplicate(s.substr(1));
//     if (ch == ans[0])
//     {
//         return ans;
//     }
//     else
//     {
//         return ch + ans;
//     }
// }

//////////////////////////////////////////// Question-4
// string Move_all_x(string s)
// {
//     if (s.length() == 0)
//     {
//         return "";
//     }
//     char ch = s[0];
//     string ans = Move_all_x(s.substr(1));
//     if (ch = 'x')
//     {
//         return ans + ch;
//     }
//     return ch + ans;
// }

//////////////////////////////////////////// Question-5

// void subseq(string s, string ans)
// {
//     if (s.length() == 0)
//     {
//         cout << ans << endl;
//         return;
//     }

//     char ch = s[0];
//     subseq(s.substr(1), ans + ch);
//     subseq(s.substr(1), ans);
// }

//////////////////////////////////////////// Question-6

void subseq(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    int code = ch;
    subseq(s.substr(1),ans);
    subseq(s.substr(1),ans + ch);
    subseq(s.substr(1),ans + to_string(code));
}