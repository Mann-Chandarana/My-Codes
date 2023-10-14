///////////////// Keypad codes

#include <iostream>
#include <vector>
using namespace std;

string mapping[9] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};
int count = 0;

void solve(string digit, string output, int index, vector<string> &ans)
{
    // base case
    if (index >= digit.length())
    {
        count++;
        ans.push_back(output);
        return;
    }

    int number = digit[index] - '0';
    string value = mapping[number - 1];

    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solve(digit, output, index + 1, ans);
        output.pop_back();
    }
}

int main()
{
    string s, output;
    cin >> s;
    vector<string> ans;
    solve(s, output, 0, ans);

    for (auto ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl
         << count;

    return 0;
}