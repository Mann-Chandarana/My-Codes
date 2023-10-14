#include <iostream>
#include <queue>
using namespace std;

class Fun
{
public:
    void operator()(string name)
    {
        cout << "My name is " << name << endl;
    }
};

int main()
{
    Fun fu;
    fu("Mann");

    priority_queue<int> q;                             /////////  Max Heap
    priority_queue<int, vector<int>, greater<int>> pq; //////// Min Heap
    int n;
    cin >> n;

    for (int i = 1; i < n; i++)
    {
        int no;
        cin >> no;
        q.push(no); // O(logN)
    }

    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }

    return 0;
}