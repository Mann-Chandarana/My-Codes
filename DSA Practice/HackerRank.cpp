#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, value;
    int aux = 0;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    // reverse(vec.begin(), vec.end());
    for (int i = 0; i < n / 2; i++)
    {
        aux = vec[n - i - 1];
        vec[n - i - 1] = vec[i];
        vec[i] = aux;
    }
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << " ";
    }

    return 0;
}