/////////////////// String window

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    string ans = "";
    map<char, int> map2;
    for (int i = 0; i < s2.length(); i++)
    {
        map2[s2[i]]++;
    }
    int i = 0, j = 0;
    map<char, int> map1;
    int mct = 0, dmct = s2.length();
    while (true)
    {
        if (s1.length() < s2.length())
        {
            ans = "No String";
            break;
        }

        bool f1 = false;
        bool f2 = false;

        ////// Acquire

        while ((j < s1.length()) && (mct < dmct))
        {
            map1[s1[j]]++;
            if (map1[s1[j]] <= map2[s1[j]])
            {
                mct++;
            }
            j++;
            f1 = true;
        }

        ////// Release
        while (mct == dmct && i < j)
        {
            string temp = s1.substr(i, j - i);
            if (ans.length() == 0 || temp.length() < ans.length())
            {
                ans = temp;
            }
            if (map1[s1[i]] == 0)
            {
                map1.erase(s1[i]);
            }
            else
            {
                map1[s1[i]]--;
            }

            if (map1[s1[i]] < map2[s1[i]])
            {
                mct--;
            }
            i++;
            f2 = true;
        }

        if (!f1 && !f2)
        {
            break;
        }
    }
    if (ans=="")
    {
        ans = "No String";
    }
    
    cout << ans << endl;

    return 0;
}