////////////////// Subsequence 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> ans;
int counte = 0;

void subsequence(string in, string out, int i)
{
    if (in[i] == '\0')
    {
        counte++;
        ans.push_back(out);
        return;
    }
   
    subsequence(in, out, i + 1);
     out.push_back(in[i]);
    subsequence(in, out, i + 1);
}

int main()
{
    string s, output;
    cin >> s;
    subsequence(s, output, 0);

    for (auto ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl
         << counte;

    return 0;
}