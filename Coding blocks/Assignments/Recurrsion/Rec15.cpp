////////////// Subset recurrsion

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool greateer(vector<int> a, vector<int> b)
{
    return a.size() < b.size();
}

vector<vector<int>> ans;
int sum = 0;
void generate_subset(int *arr, int n, int i, int k, vector<int> out)
{
    if (i == n)
    {
        for (auto i : out)
        {
            sum += i;
        }
        if (sum == k)
        {
            ans.push_back(out);
        }
        out.clear();
        sum = 0;
        return;
    }
    generate_subset(arr, n, i + 1, k, out);
    out.push_back(arr[i]);
    generate_subset(arr, n, i + 1, k, out);
}

int main()
{
    int n, k;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;
    reverse(arr, arr + n);

    vector<int> output;
    generate_subset(arr, n, 0, k, output);
    sort(ans.begin(), ans.end());
    sort(ans.begin(), ans.end(),greateer);

    for (auto i : ans)
    {
        for (auto ele : i)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    delete[] arr;
    return 0;
}