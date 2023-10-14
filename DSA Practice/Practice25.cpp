#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int t, query, element;
    cin >> t;
    queue<int> q1;
    while (t--)
    {
        cin >> query;
        if (query == 1)
        {
            cin >> element;
            q1.push(element);
        }
        else if (query == 2)
        {
            q1.pop();
        }
        else
        {
            cout << q1.front() << endl;
        }
    }

    return 0;
}