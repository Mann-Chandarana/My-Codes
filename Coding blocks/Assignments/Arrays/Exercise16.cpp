#include <iostream>
typedef long long int ll;
using namespace std;

int main()
{
    int n;
    cin >> n;
    int odd = 0, even = 0;
    int count = 1;

    while (n != 0)
    {
        if (count & 1)
        {
            odd += (n % 10);
            count++;
        }
        else
        {
            even += (n % 10);
            count++;
        }

        n /= 10;
    }

    cout << odd << endl
         << even << endl;

    return 0;
}

