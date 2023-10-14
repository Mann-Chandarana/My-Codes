////////////// lexographical order

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> ans;
void sorted_lexo(int in, int i)
{
    if (i == in+1)
    {
        return;
    }
    ans.push_back(to_string(i));
    sorted_lexo(in, i + 1);
}

int main()
{
    int in;
    cin >> in;
    sorted_lexo(in, 0);
    sort(ans.begin(), ans.end());
    for (auto ele : ans)
    {
        cout << ele << " ";
    }

    return 0;
}