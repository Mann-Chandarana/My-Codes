#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string *strings;
    strings = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> strings[i];
    }
    //////////////////////////////////////////////////
    int m;
    cin >> m;
    string *queries;
    queries = new string[m];
    int arr[m] = {0};
    for (int i = 0; i < m; i++)
    {
        cin >> queries[i];
    }
    /////////////////////////////////////////////////////////
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (strings[i] == queries[j])
            {
                arr[j]++;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
