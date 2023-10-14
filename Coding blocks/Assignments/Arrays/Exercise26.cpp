/////////////// Maximum sum path in two array

#include <iostream>
using namespace std;

int main()
{
    int t, N, M, *arr1, *arr2;
    cin >> t;

    while (t--)
    {
        cin >> N >> M;
        arr1 = new int[N];
        arr2 = new int[M];

        for (int i = 0; i < N; i++)
        {
            cin >> arr1[i];
        }

        for (int i = 0; i < M; i++)
        {
            cin >> arr2[i];
        }

        int i = 0, j = 0, sum = 0;

        int result = 0, sum1 = 0, sum2 = 0;

        while (i < N && j < M)
        {
            if (arr1[i] < arr2[j])
            {
                sum1 += arr1[i];
                i++;
            }
            else if (arr1[i] > arr2[j])
            {
                sum2 += arr2[j];
                j++;
            }

            else
            {
                result += max(sum1, sum2) + arr1[i];

                sum1 = 0;
                sum2 = 0;

                i++;
                j++;
            }
        }
        while (i < N)
        {
            sum1 += arr1[i];
            i++;
        }

        while (j < M)
        {
            sum2 += arr2[j];
            j++;
        }

        result += max(sum1, sum2);

        cout << result << endl;
    }

    delete (arr1);
    delete (arr2);

    return 0;
}