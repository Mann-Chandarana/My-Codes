/////////////// Generate paranthesis

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> ans;

void generate(string a, int i, int open, int close, int n)
{
    if (i == 2 * n)
    {
        ans.push_back(a);
        return;
    }
    if (open < n)
    {
        a.push_back('(');
        generate(a, i + 1, open + 1, close, n);
        a.pop_back();
    }
    if (close < open)
    {
        a.push_back(')');
        generate(a, i + 1, open, close + 1, n);
    }
}

int main()
{
    int n;
    cin >> n;

    string inp;

    generate(inp, 0, 0, 0, n);
    reverse(ans.begin(), ans.end());
    for (auto ele : ans)
    {
        cout << ele << endl;
    }

    return 0;
}