#include <iostream>
#include <map>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size, value, sum = 0, high = -1;
        cin >> size;
        map<int, int> count;
        for (int i = 0; i < size; i++)
        {
            cin >> value;
            count[value]++;
        }
        for (auto x : count)
        {
            if (high < x.second)
            {
                high = x.second;
            }
            sum += x.second;
        }
        if (high == size)
        {
            cout << "0" << endl;
        }
        else if (high <= 1 && size >= 2)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << (sum - high + 1) << endl;
        }
    }

    return 0;
}