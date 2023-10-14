////////// next greater element

#include <iostream>
#include <stack>
using namespace std;

int *larger_element(int* vec1,int n)
{
    int *ans = new int[n];
    stack<int> s;
    s.push(-1);

    for (int i = n-1; i >= 0; i--)
    {
        int curr = vec1[i];
        while (s.top() != -1 && s.top() <= curr)
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(curr);
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int *vec1, *ans;
        vec1 = new int[n];
        ans = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> vec1[i];
        }
        ans = larger_element(vec1,n);
        for (int i = 0; i < n; i++)
        {
            cout << vec1[i] << "," << ans[i] << endl;
        }
    }
    return 0;
}