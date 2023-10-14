#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int t, N, K;
    cin >> t;

    while (t--)
    {
        cin >> N >> K;
        int *arr = new int[N];

        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        unordered_map<int, int> m;
        int distinct = 0;

        for (int i = 0; i < K; i++)
        {
            if (m[arr[i]] == 0)
            {
                distinct++;
            }
            m[arr[i]]++;
        }
        cout << distinct << " ";

        for (int i = K; i < N; i++)
        {
            if (m[arr[i - K]] == 1)
            {
                distinct--;
            }
            m[arr[i - K]] -= 1;

            if (m[arr[i]] == 0)
            {
                distinct++;
            }
            m[arr[i]]++;

            cout << distinct << " ";
        }
        cout << endl;

        delete[] arr;
    }

    return 0;
}