#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> get_aint_prime_factor(int n)
{
    vector<int> v;

    for (int i = 2; i <= sqrt(n); i++)
    {
        while (n % i == 0)
        {
            v.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
    {
        v.push_back(n);
    }

    return v;
}

int compute_sum(vector<int> arr)
{
    int sum = 0;
    for (auto i : arr)
    {
        while (i)
        {
            sum += i % 10;
            i /= 10;
        }
    }

    return sum;
}

bool is_boston(int num)
{
    int x = num, sum = 0;
    while (x)
    {
        sum += x % 10;
        x /= 10;
    }

    vector<int> v = get_aint_prime_factor(num);
    int sum2 = compute_sum(v);
    return sum == sum2;
}
int main()
{
    int x;
    cin >> x;
    cout << is_boston(x);
    return 0;
}