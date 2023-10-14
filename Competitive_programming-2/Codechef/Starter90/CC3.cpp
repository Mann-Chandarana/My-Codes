/* Printing Binary Array */

/* Approach :- Here approach is to print the compliement of the given nubmer */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N;
        cin >> N;

        vector<int> vec(N);

        for (int i = 0; i < N; i++)
            cin >> vec[i];

        for (auto element : vec)
        {
            int temp = element == 0 ? 1 : 0;
            cout<<temp<<" ";
        }
        cout<<endl;
    }

    return 0;
}