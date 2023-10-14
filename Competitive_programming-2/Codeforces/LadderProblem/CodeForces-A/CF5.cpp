/* https://codeforces.com/problemset/problem/122/A */

/* Lucky Divison :- 1000 */

#include <bits/stdc++.h>
using namespace std;

#define fastread() (ios_base::sync_with_stdio(false), cin.tie(NULL))

int main()
{
    fastread();
    int n;
    cin >> n;

    bool answer = false;

    if ((n % 4 == 0) or (n % 7 == 0) or (n % 44 == 0) or (n % 47 == 0) or (n % 74 == 0) or (n % 77 == 0) or (n % 444 == 0) or
        (n % 447 == 0) or (n % 474 == 0) or(n%477==0) or (n % 744 == 0) or (n % 747 == 0) or (n%774==0) or (n % 777 == 0))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}