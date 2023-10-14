// Initially, Chef is at coordinate 0 on X-axis. For each i=1,2,…,N in order, Chef does the following:

// If Chef is at a non-negative coordinate, he moves i steps backward (i.e, his position's coordinate decreases by i), otherwise he moves i steps forward (i.e, his position's coordinate increases by i).
// You are given the integer N. Find the final position of Chef on the X-axis after N operations.

#include <iostream>
typedef long long int ll;
using namespace std;

int main()
{
    ll t, N, steps = 0;
    cin >> t;
    while (t--)
    {
        cin >> N;
        if (N % 2 == 0)
        {
            cout << N / 2 << endl;
        }
        else
        {
            cout << -(N / 2 + 1) << endl;
        }
    }

    return 0;
}