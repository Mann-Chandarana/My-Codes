/* Power Set :- https://practice.geeksforgeeks.org/problems/power-set4302/1 */

#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()

vector<string> AllPossibleStrings(string s)
{
    int n = s.length();
    vector<string> answer;

    for (int i = 1; i < (1 << n); i++)
    {
        string str = "";
        for (int j = 0; j <= 31; j++)
        {
            if (i & (1 << j))
                str += s[j];
        }
        answer.push_back(str);
    }
    sort(all(answer));
    return answer;
}

int main()
{
    vector<string> answer = AllPossibleStrings("aa");

    for (auto element : answer)
        cout << element << endl;

    return 0;
}