///////////////////// Subsequences Ascii subsequences

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void subsequence(string s, string output, int i, int &count)
{
    if (s[i] == '\0')
    {
        count++;
        cout << output << " ";
        return;
    }

    subsequence(s, output, i + 1, count);
    output.push_back(s[i]);
    subsequence(s, output, i + 1, count);
    output.pop_back();
    subsequence(s, output + to_string(int(s[i])), i + 1, count);
}

int main()
{
    string sub, out;
    int count = 0;
    cin >> sub;
    subsequence(sub, out, 0, count);
    cout << endl
         << count;

    return 0;
}