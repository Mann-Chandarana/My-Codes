///////////////// Subset sum easy

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void generate_subset(int *arr, int n, int i, vector<int> out, bool &isTrue)
{
    if (i == n)
    {
        if (out.size() > 0)
        {
            int sum = 0;
            for (auto i : out)
            {
                sum += i;
            }
            if (sum == 0)
            {
                isTrue = true;
            }
        }

        return;
    }
    out.push_back(arr[i]);
    generate_subset(arr, n, i + 1, out, isTrue);
    out.pop_back();
    generate_subset(arr, n, i + 1, out, isTrue);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;

        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        vector<int> output;
        bool is_true = false;
        generate_subset(arr, n, 0, output, is_true);
        if (is_true)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }

        delete[] arr;
    }

    return 0;
}