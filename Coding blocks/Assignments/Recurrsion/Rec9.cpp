/////////////////// Subsequence

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> ans;

void subsequence(string s, string output, int i)
{
    if (s[i] == '\0')
    {
        ans.push_back(output);
        return;
    }

    output.push_back(s[i]);
    subsequence(s, output, i + 1);
    output.pop_back();
    subsequence(s, output, i + 1);
}

int main()
{
    int n;
    cin >> n;

    while (n--)
    {
        string sub, out;
        cin >> sub;
        subsequence(sub, out, 0);

        sort(ans.begin(), ans.end());
        for (auto i : ans)
        {
            cout << i << endl;
        }
        ans.clear();
    }

    return 0;
}