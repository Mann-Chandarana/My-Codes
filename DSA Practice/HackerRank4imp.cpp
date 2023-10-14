
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N = 0, Q = 0;
    int lastans = 0;
    int type, x, y;
    int seq = 0;
    int pos;

    cin >> N >> Q;

    vector<vector<int>> a(N);

    for (int i = 0; i < Q; i++)
    {
        cin >> type >> x >> y;
        seq = ((x ^ lastans) % N);
        // cout << seq << endl;
        if (type == 1)
        {
            a[seq].push_back(y);
            // cout << (seq) << " <-- " << y << endl;
        }
        else if (type == 2)
        {
            pos = (y % a[seq].size());
            //cout << "pos " << pos << endl;
            lastans = a[seq][pos];
            cout << lastans << endl;
        }
    }
    return 0;
}

// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     int size, query;
//     cin >> size >> query;
//     int lastAnswer = 0, var, var1;
//     vector<vector<int>> vec1;
//     vector<int> temp[size];
//     while (query--)
//     {
//         int arr[3];
//         for (int i = 0; i < 3; i++)
//         {
//             cin >> arr[i];
//         }
//         if (arr[0] == 1)
//         {
//             var = ((arr[1] ^ lastAnswer) % 2);
//             temp[var].push_back(arr[2]);
//         }

//         if (arr[0] == 2)
//         {
//             for (int i = 0; i < size; i++)
//             {
//                 vec1.push_back(temp[i]);
//             }
//             var = ((arr[1] ^ lastAnswer) % 2);
//             lastAnswer = vec1[var][arr[2]];
//             cout << lastAnswer << endl;
//         }
//     }

//     return 0;
// }