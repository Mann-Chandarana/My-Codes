///////// Concat sort

#include <bits/stdc++.h>
using namespace std;

bool isSorted1(deque<int> vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i] > vec[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<int> vec(n);

        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }

        deque<int> q1, q2;

        for (int i = 0; i < n; i++)
        {
            if (q1.empty())
            {
                q1.push_back(vec[i]);
                continue;
            }

            if (vec[i] > q1.back())
            {
                q1.push_back(vec[i]);
            }
            else
            {
                // for (int i = 0; i < q1.size(); i++)
                // {
                //     cout << q1[i] << " ";
                // }
                // cout << endl;
                int j = q1.size() - 1;
                while (j >= 0 && vec[i] < q1[j])
                {
                    if (vec[i] > q1[j])
                    {
                        break;
                    }

                    if (!q2.empty() and q1[j] < q2.front())
                    {
                        // cout << q2.front() << " " << q1[j] << endl;
                        q2.push_front(q1[j]);
                    }
                    else
                    {
                        q2.push_back(q1[j]);
                    }

                    q1.pop_back();
                    j--;
                }
                q1.push_back(vec[i]);
            }
        }

        // for (int i = 0; i < q1.size(); i++)
        // {
        //     cout << q1[i] << " ";
        // }
        // cout << "\n";
        // for (int i = 0; i < q2.size(); i++)
        // {
        //     cout << q2[i] << " ";
        // }
        // cout << "\n";

        if (isSorted1(q1) and isSorted1(q2) and q1[q1.size() - 1] < q2[0])
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}