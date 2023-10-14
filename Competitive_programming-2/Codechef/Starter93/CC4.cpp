/* Break free codechef  */

// https://www.codechef.com/START93C/problems/REMOSET?tab=statement

#include <iostream>
using namespace std;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int num;
        cin >> num;
        int eve = 0;
        for (int i = 0; i < num; i++)
        {
            int v = 0;
            cin >> v;
            if (v % 2 == 0)
                eve++;
        }
        long long cnt = eve;
        long long a = 1, modu = 1e9 + 7;
        while (cnt > 0)
        {
            a *= 2;
            a %= modu;
            cnt--;
        }
        if (num == eve)
            a--;
        cout << a << endl;
    }
    return 0;
}