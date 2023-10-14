#include <iostream>
using namespace std;

int main()
{
    int t, N, M;
    cin >> t;

    while (t--)
    {
        cin >> M >> N;
        int i = 1, ayush = 0, harshit = 0;
        bool Ayush_true = true, Harshit_true = false;

        while (true)
        {
            if (Ayush_true)
            {
                if (ayush <= M)
                {
                    ayush += i;
                }
                else
                {
                    cout << "Harshit" << endl;
                    break;
                }
            }
            else if (Harshit_true)
            {
                if (harshit <= N)
                {
                    harshit += i;
                }
                else
                {
                    cout << "Aayush" << endl;
                    break;
                }
            }
            Ayush_true = !Ayush_true;
            Harshit_true = !Harshit_true;
            i++;
        }
    }

    return 0;
}