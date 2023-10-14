///////////////// Split array

#include <vector>
using namespace std;

int ans = 0;

void split_array(int i, int n, int *arr, int sum1, vector<int> &arr1, int sum2, vector<int> &arr2)
{
    if (i == n)
    {
        if (sum1 == sum2)
        {
            ans++;
            for (auto ele1 : arr1)
            {
                cout << ele1 << " ";
            }
            cout << "and ";
            for (auto ele2 : arr2)
            {
                cout << ele2 << " ";
            }
            cout << endl;
        }

        return;
    }
    sum1 += arr[i];
    arr1.push_back(arr[i]);
    split_array(i + 1, n, arr, sum1, arr1, sum2, arr2);
    sum1 -= arr[i];
    arr1.pop_back();

    arr2.push_back(arr[i]);
    sum2 += arr[i];
    split_array(i + 1, n, arr, sum1, arr1, sum2, arr2);
    sum2 -= arr[i];
    arr2.pop_back();
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    vector<int> arr1, arr2;
    int sum1 = 0, sum2 = 0;
    split_array(0, n, arr, sum1, arr1, sum2, arr2);
    cout << ans << endl;
    delete[] arr;

    return 0;
}