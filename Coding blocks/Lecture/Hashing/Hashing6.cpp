////////// Find the smallest window in a string containing all the character of other string

/*
   1) Brute for will be --->  O(n^3)

   2) using sliding window + hashmap

   points for this question

   1) if pf >sf
         then return false

   2) make a pattern frequency array for using hashmap and init it with freq of characters

   3) expand towards right tp get the window once you get the window you contract from left side to
      avoid  un required characters (either character is not present or its frequecy is greater than the pattern frequency)

    4) every you get a window update your min window by doing comarion between current window and minimun window you got till now

    5) output the new window
*/

#include <bits/stdc++.h>
using namespace std;

string find_window(string s, string pat)
{
    int sl = s.length();
    int pl = pat.length();

    if (pl > sl)
    {
        return "NONE";
    }

    // 2 freq map
    int FS[256] = {0};
    int FP[256] = {0};

    for (int i = 0; i < pl; i++)
    {
        char ch = pat[i];
        FP[ch]++;
    }

    int cnt = 0;
    int start = 0;
    int min_len = INT_MAX;
    int start_idx = -1;

    /// 3  sliding window (expansion + contarction + update the min length window)

    for (int i = 0; i < sl; i++)
    {
        char ch = s[i];
        FS[ch]++;

        // Maintain the cnt of character

        if (FP[ch] != 0 and FS[ch] <= FP[ch])
        {
            cnt++;
        }

        // if all the character matches
        if (cnt == pl)
        {
            // start shrinking the window
            char temp = s[start];
            ///// loop to remove all un wanted characters
            while (FP[temp] == 0 or FS[temp] > FP[temp])
            {
                FS[temp]--;
                start++;
                temp = s[start];
            }

            // window size
            int window_length = i - start + 1;
            if (window_length < min_len)
            {
                min_len = window_length;
                start_idx = start;
            }
        }

        if (start_idx == -1)
        {
            return "NONE";
        }

        string ans = s.substr(start_idx, min_len);
        return ans;
    }
}

int main()
{

    return 0;
}