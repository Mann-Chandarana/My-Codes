////////// Merge Sorted linked list

#include <bits/stdc++.h>
using namespace std;

void merge(list<int> l1, list<int> l2)
{
    list<int> l3;
    while (!l1.empty() && !l2.empty())
    {
        if (l1.front() <= l2.front())
        {
            l3.push_front(l1.front());
            l1.pop_front();
        }
        else
        {
            l3.push_front(l2.front());
            l2.pop_front();
        }
    }
    while (!l1.empty())
    {
        l3.push_front(l1.front());
        l1.pop_front();
    }
    while (!l2.empty())
    {
        l3.push_front(l2.front());
        l2.pop_front();
    }
    while (!l3.empty())
    {
        cout << l3.back() << " ";
        l3.pop_back();
    }
    cout << endl;
}

int main()
{
    int t, n1, n2;
    cin >> t;

    while (t--)
    {
        cin >> n1;
        list<int> list1, list2;
        int ele;
        for (int i = 0; i < n1; i++)
        {
            cin >> ele;
            list1.push_back(ele);
        }
        cin >> n2;
        for (int i = 0; i < n2; i++)
        {
            cin >> ele;
            list2.push_back(ele);
        }

        merge(list1, list2);
    }

    return 0;
}