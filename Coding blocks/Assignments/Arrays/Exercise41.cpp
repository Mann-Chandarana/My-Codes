////////////////////////// Form biggest number

// #include <algorithm>
// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int myCompare(string X, string Y)
// {
//     string XY = X.append(Y);

//     string YX = Y.append(X);

//     return XY.compare(YX) > 0 ? 1 : 0;
// }

// void printLargest(vector<string> arr)
// {
//     sort(arr.begin(), arr.end(), myCompare);

//     for (int i = 0; i < arr.size(); i++)
//     {
//         cout << arr[i];
//     }
// }

// int main()
// {
//     int t, n;
//     cin >> t;
//     string no;

//     while (t--)
//     {
//         cin >> n;
//         vector<string> arr(n);

//         for (int i = 0; i < n; i++)
//         {
//             cin >> no;
//             arr.push_back(no);
//         }

//         printLargest(arr);
//     }

//     return 0;
// }

////////////////////////////// Can you read this

#include <iostream>
using namespace std;

void Dupword(string str)
{
    string word;
    word.push_back(str[0]);
    for (int i = 1; i < str.length(); i++)
    {
        if (isupper(str[i]))
        {
            cout << word << endl;
            word = "";
            word.push_back(str[i]);
        }
        else
        {
            word.push_back(str[i]);
        }
    }
    cout << word << endl;
}

int main()
{
    string s;
    cin >> s;

    Dupword(s);

    return 0;
}
