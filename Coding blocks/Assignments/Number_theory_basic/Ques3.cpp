///////////////// Prime visits

#include <iostream>
typedef long long ll;
using namespace std;

void prime_sieve(ll *p)
{
    p[1] = p[0] = 0;
    p[2] = 1;

    for (ll i = 3; i <= 100000; i += 2)
    {
        p[i] = 1;
    }

    for (ll i = 3; i <= 100000; i += 2)
    {
        if (p[i] == 1)
        {
            for (ll j = i * i; j <= 100000; j += i)
            {
                p[j] = 0;
            }
        }
    }
}

int main()
{
    ll p[100000] = {0};
    prime_sieve(p);

	ll csum[100000] = {0};

	for(int i=1;i<=100000;i++)
	{
		csum[i] = csum[i-1]+p[i];
	}
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;
        cout << csum[b]-csum[a-1] << endl;
    }

    return 0;
}