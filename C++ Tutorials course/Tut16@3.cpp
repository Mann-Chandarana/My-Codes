#include <iostream>
using namespace std;
//////////////////////////////////////////////////////////////////////////////////////
// 1) Reversing a string using recusrsion
// void reverse(string s)
// {
//     if (s.length()==0)// base case
//     {
//         return;
//     }
//     string ros = s.substr(1);
//     reverse(ros);
//     cout<<s[0];
// }
// int main()
// {
//     reverse("binod");
//     return 0;
// }

//////////////////////////////////////////////////////////////////////////////////////
// 2) Replace pi by 3.14

// void replacePi(string s)
// {
//     if (s.length() == 0) // base case
//     {
//         return;
//     }
//     if (s[0] == 'p' && s[1] == 'i')
//     {
//         cout << "3.14";
//         replacePi(s.substr(2));
//     }
//     else
//     {
//         cout << s[0];
//         replacePi(s.substr(1));
//     }
// }

// int main()
// {
//     replacePi("pixpynpimpi");
//     return 0;
// }

//////////////////////////////////////////////////////////////////////////////////////
// 3) Tower of hanoi
// void towerofHonai(int n, char scr, char dest, char help)
// {
//     if (n==0)
//     {
//         return;
//     }

//     towerofHonai(n-1,scr,help,dest);
//     cout<<"Move from "<<scr<<" to "<<dest<<endl;
//     towerofHonai(n-1,help,dest,scr);

// }

// int main()
// {
//     towerofHonai(3,'A','C','B');
//     return 0;
// }

//////////////////////////////////////////////////////////////////////////////////////
//4) Remove duplicates from string

// string removeDup(string s)
// {
//     if (s.length() == 0)
//     {
//         return "";
//     }
//     char ch = s[0];
//     string ans = removeDup(s.substr(1));
//     if (ch == ans[0])
//     {
//         return ans;
//     }
//     return (ch + ans);
// }
// int main()
// {
//     cout << removeDup("aaaabcccdddd") << endl;
//     return 0;
// }

//////////////////////////////////////////////////////////////////////////////////////
//5) Move all x to the end of the string
string moveallX(string s)
{
    if (s.length() == 0)
    {
        return "";
    }

    char ch = s[0];
    string ans = moveallX(s.substr(1));
    if (ch == 'x')
    {
        return ans + ch;
    }
    return ch + ans;
}
int main()
{
    cout<<moveallX("abgcxxgsywwxy")<<endl;
    return 0;
}

