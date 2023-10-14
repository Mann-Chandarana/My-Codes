#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, Total;
        cin >> n1 >> n2 >> Total;
        vector<int> v(n1);
        vector<int> v1(n2);
        for (int i = 0; i < n1; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n2; i++)
        {
            cin >> v1[i];
        }
        int count = 0, sum = 0;
        int i = 0, j = 0;
        while ((sum <= Total) && (i < n1))
        {
            sum += v[i];
            i++;
        }
        while ((sum <= Total) && (j < n2))
        {
            sum += v1[j];
            j++;
        }
        count = i + j;
        cout << count << endl;
    }
    return 0;
}