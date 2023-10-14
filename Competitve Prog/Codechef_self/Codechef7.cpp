#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int coins;
        vector<int> v1(2);
        cin >> v1[0] >> v1[1] >> coins;
        sort(v1.begin(), v1.end());
        if (v1[0] != v1[1])
        {
            while (v1[0] != v1[1] && coins != 0)
            {
                v1[0]++;
                coins--;
            }
        }
        cout << v1[1] - v1[0] << endl;
    }

    return 0;
}