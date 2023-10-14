//////////////////// Help ramu

#include <iostream>
using namespace std;

int main()
{
    int t, c1, c2, c3, c4, n, m;
    cin >> t;

    while (t--)
    {
        int R_mini = 0, C_mini = 0;
        cin >> c1 >> c2 >> c3 >> c4;
        cin >> n >> m;
        int rick[n], cabs[m];

        for (int i = 0; i < n; i++)
        {
            cin >> rick[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> cabs[i];
        }

        for (int i = 0; i < n; i++)
        {
            R_mini += min(rick[i] * c1, c2);
        }
        R_mini = min(R_mini, c3);

        for (int i = 0; i < m; i++)
        {
            C_mini += min(cabs[i] * c1, c2);
        }
        C_mini = min(C_mini, c3);

        // cout << R_mini << " " << C_mini << endl;

        cout << min(R_mini + C_mini, c4) << endl;
    }

    return 0;
}