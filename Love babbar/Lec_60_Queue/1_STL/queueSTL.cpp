#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    cout << "Empty: " << q.empty() << endl;

    // cout << "Front: " << q.front() << endl;
    // cout << "Back: " << q.back() << endl; // Error code crash

    q.pop();

    q.push(1);
    q.push(7);
    cout << "Empty: " << q.empty() << endl;
    q.push(12);
    q.push(2);
    q.push(26);

    cout << "Front: " << q.front() << endl;
    cout << "Back: " << q.back() << endl;

    q.pop();
    cout << "Front after pop: " << q.front() << endl;
    cout << "Back after pop: " << q.back() << endl;

    cout << "Size: " << q.size() << endl;

    return 0;
}