/////////////////// Piyush and magical park

#include <iostream>
using namespace std;

int main()
{
    int N, M, K, S;
    cin >> N >> M >> K >> S;

    char **arr = new char *[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = new char[M];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < M; col++)
        {
            if (S >= K)
            {
                if (arr[row][col] == '.')
                {
                    if (col != M - 1)
                    {
                        S -= 3;
                    }
                    else
                    {
                        S -= 2;
                    }
                }

                if (arr[row][col] == '*' )
                {
                    if (col != M - 1)
                    {
                        S += 4;
                    }
                    else
                    {
                        S += 5;
                    }
                    
                    
                }

                if (arr[row][col] == '#')
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    if (S >= K)
    {
        cout << "Yes" << endl;
        cout << S << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    for (int i = 0; i < N; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return 0;
}