#include <bits/stdc++.h>
using namespace std;

void subSets(vector<int> &v, vector<int> &temp, int &start)
{
    if (start >= v.size())
    {
        for (int i = 0; i < temp.size(); i++)
            cout << temp[i] << " ";
        cout << endl;
        return;
    }

    // Include case
    temp.push_back(v[start]);
    subSets(v, temp, ++start);
    temp.pop_back();
    start--;
    // Exclude case
    subSets(v, temp, ++start);
    start--;

    // We can do this in different way also: first take exclue case and then take include case.
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int start = 0;
    vector<int> temp;
    cout << endl << endl;
    subSets(v, temp, start);

    return 0;
}