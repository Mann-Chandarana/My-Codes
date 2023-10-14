#include <bits/stdc++.h>
using namespace std;

void moveZeros(vector<int> &v)
{
    int i = 0;

    for(int j = 0; j < v.size(); j++)
    {
        if (v[j] != 0)
        {
            swap(v[j], v[i]);
            i++;
        }
    }
}
int main()
{

    return 0;
}
