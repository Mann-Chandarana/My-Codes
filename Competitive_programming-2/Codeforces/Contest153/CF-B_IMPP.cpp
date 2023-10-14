// https://codeforces.com/contest/1860/problem/B 

/*
Solution:-

1) Here we will find the minimum of 
   a) (how many coin with value one is required ) and 
   b) (how many coin with value k is required)

a) So in this part we will find the "value" which is remaining after using "ak" coins
   and then we will subtrack "a1" coins from that "value"

b) Here we will find the number of coins required with value k and value 1
   if a1 > required number of coin with value 1
       then we will convert the remaninig coins with value 1 to remaining coin with value k
    
    required_one = a1-value%k
    oneconvertedtok = left1coin/k

    total = required_k+ required_one - oneconvertedtok
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll m, k, a1, ak;
    cin >> m >> k >> a1 >> ak;

    ll ans = min(m / k, ak);
    ll value = m - (ans * k);

    if (value <= a1)
        cout << 0 << endl;
    else
    {
        ///////// Finding the number of coins required with value 1
        ll required_1 = value - a1;


        ///////// Finding the number of coins required with value k
        /* Here catch is we have to minus the coins which we can convert to k from the left number of coins with value 1 */
        ll required_k = (value / k);
        ll needed_one = max(0,(int)(value%k-a1));
        ll left_coin = max(0,(int)(a1-(value%k)));
        ll oneConvertedTok = (left_coin / k);

        required_k = required_k + needed_one - oneConvertedTok;

        cout << min(required_1, required_k) << endl;
    }
}

int main()
{
    ll t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}