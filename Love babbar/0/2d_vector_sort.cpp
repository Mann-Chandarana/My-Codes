#include "bits/stdc++.h"

using namespace std;
 /*
bool isPrime(int n)
{
    if(n < 2)
        return 0;
    for(int i = 2;i<=sqrt(n);i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}
*/
void print(vector<vector<int>> &v)
{
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[0].size();j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

bool cmp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int main()
{
    vector<vector<int>> v(3,vector<int>(3,0));
    
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            int ele;
            cin >> ele;
            v[i][j] = ele;
        }
    }
    
    int row = v.size();
    
    cout << "Before sorting: \n";
    print(v);
    // sort(v[0].begin(), v[0].end()); // Will only sort 0 index row
    
    for(int i=0;i<row;i++)
    {
        sort(v[i].begin(), v[i].end());
    } // Sort every row. Doest sort in column manner.
    
    sort(v.begin(), v.end(), cmp); // Sort by 1st column.
     
    cout << "After sorting: \n";
    print(v);
    
    
    return 0;
}
