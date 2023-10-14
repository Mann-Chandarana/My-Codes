#include <iostream>
#include <stack>
using namespace std;

//////////////////////////////////////////////
void insert_At_Bottom(stack<int> &sp, int element)
{
    if (sp.empty())
    {
        sp.push(element);
        return;
    }

    int topel = sp.top();
    sp.pop();
    insert_At_Bottom(sp, element);
    sp.push(topel);
}
//////////////////////////////////////////////
void reverse(stack<int> &sp)
{
    if (sp.empty())
    {
        return;
    }

    int element = sp.top();
    sp.pop();
    reverse(sp);
    insert_At_Bottom(sp, element);
}
//////////////////////////////////////////////
int main()
{
    stack<int> sp;
    int n, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        sp.push(x);
    }
    reverse(sp);

    while (!sp.empty())
    {
        cout << sp.top() << " ";
        sp.pop();
    }

    return 0;
}