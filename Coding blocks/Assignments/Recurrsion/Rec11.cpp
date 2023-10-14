////////////////  Codes of string

#include <iostream>
#include <vector>
using namespace std;

vector<string> ans;

char arr[] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

void code_of_string(string s, string output, int i, int n)
{
    if (s[i] == '\0')
    {
        ans.push_back(output);
        return;
    }
    int digit = (s[i] - '0');
    output.push_back(arr[digit]);
    code_of_string(s, output, i + 1, n);
    output.pop_back();

    if ((i + 1 < n))
    {
        int digit2 = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if (digit2 <= 26)
        {
            output.push_back(arr[digit2]);
            code_of_string(s, output, i + 2, n);
            output.pop_back();
        }
    }
}

int main()
{
    string s, out;
    cin >> s;
    code_of_string(s, out, 0, s.length());
    int n = ans.size();

    cout << "[";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << ans[i];
        }
        else
        {
            cout << ans[i] << ", ";
        }
    }

    cout << "]" << endl;

    return 0;
}