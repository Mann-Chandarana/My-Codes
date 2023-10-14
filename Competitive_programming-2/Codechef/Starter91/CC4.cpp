#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k, n1, n2;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr.begin(), arr.end(), greater<int>());
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> mp;

        while (k--)
        {
            cin >> n1 >> n2;
            for (int i = n1; i <= n2; i++)
                mp[i]++;
        }
        for (auto element : mp)
        {
            pq.push({element.second, element.first});
        }
        int sum = 0;
        int i = 0;
        vector<int> answer(n, -1);
        while (!pq.empty())
        {
            int index = pq.top().second;
            int frequency = pq.top().first;
            pq.pop();
            sum += arr[i] * frequency;
            answer[index-1] = arr[i];
            i++;
        }

        for (int j = 0; j < n; j++)
        {
            if (answer[j] == -1)
            {
                answer[j] = arr[i];
                i++;
            }
        }
        cout << sum << endl;
        for (auto element : answer)
        {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}