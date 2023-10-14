#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    int N;

    while (t--)
    {
        cin >> N;
        int x;
        int oddA = 0, evenA = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> x;
            if (x % 2 == 0)
            {
                evenA++;
            }
            else
            {
                oddA++;
            }
        }
        int even = N / 2;
        int odd = N / 2 + N % 2;

        cout << min(oddA, even) + min(evenA, odd) << endl;
    }

    return 0;
}