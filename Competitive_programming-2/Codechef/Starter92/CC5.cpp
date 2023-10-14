/* Tile coloring */

#include <iostream>
using namespace std;

int main()
{
    int t;

    cin >> t;

    while (t--)
    {
        int N, K;
        cin >> N >> K;

        long long sum = K;
        K--;
        N--;

        while (N > 0 && K > 0)
        {

            sum = (sum * K) % 1000000007;
            N--;
            K--;
        }

        cout << sum << endl;
    }

    return 0;
}
