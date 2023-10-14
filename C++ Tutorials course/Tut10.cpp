#include <iostream>
using namespace std;

// int main()
// {
//     char arr[100];
//     cin >> arr; // Input of string
//     cout << arr<<"\n"; // output of string
//     cout << arr[3]; // output of string

//     return 0;
// }

////////////// Plaindrome
// int main()
// {
//     int n;
//     cin >> n;

//     char arr[n + 1];
//     cin >> arr;

//     bool check = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] != arr[n - 1 - i])
//         {
//             check = 0;
//             break;
//         }
//     }
//     if (check == true)
//     {
//         cout << "Word is palindrom!";
//     }
//     else
//     {
//         cout << "Word is not palindrome!";
//     }

//     return 0;
// }
/////////// largest word

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    char arr[n + 1];

    cin.getline(arr, n);
    cin.ignore();
    int i = 0;
    int currLen = 0, maxLen = 0;
    int st = 0, maxst = 0;

    while (1)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (currLen > maxLen)
            {
                maxLen = currLen;
                maxst= st;
            }
            currLen = 0;
            st= i+1;
        }
        else
        {
            currLen++;
        }

        if (arr[i] == '\0')
        {
            break;
        }
        i++;
    }
    cout << maxLen << endl;
    for (int i = 0; i < maxst; i++)
    {
        cout<<arr[i+maxst];
    }
    

    return 0;
}