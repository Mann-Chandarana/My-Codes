#include "bits/stdc++.h"
using namespace std;

int checkForPalindrome_myCode(string s, int k)
// We can also make function with bool return type.
{
    for (int i = 0; i < s.size() - k + 1; i++) // O(N)
    {
        int start = i;
        int end = start + k - 1;
        while (start < end) // O(k)
        {
            if (s[start] == s[end])
            {
                start++;
                end--;
            }
            else
                break;
        }
        if ((start == end) or (end == start - 1))
            return i;
    }
    return -1;
}

bool isPalindrome(int n)
{
    int temp = n, number = 0;

    // This loop will create reverse of n. If revers of n is same as n, then palindrome.
    while (temp > 0)
    {
        number = number * 10 + temp % 10;
        temp /= 10;
    }
    if (number == n)
        return true;
    return false;
}

int findPalindromicSubArray(vector<int> arr, int k)
{
    int num = 0;
    for (int i = 0; i < k; i++)
        num = num * 10 + arr[i];
    if (isPalindrome(num))
        return 0;

    for (int j = k; j < arr.size(); j++)
    {
        num = (num % (int)pow(10, k - 1)) * 10 + arr[j];

        if (isPalindrome(num))
            return j - k + 1;
    }

    return -1;
}

int main()
{
    string s = "235115";
    int k = 4;
    int startIdx = checkForPalindrome_myCode(s, k);
    cout << "Answer of my code: " << endl;
    if (startIdx == -1)
        cout << "Doesn't exist" << endl;
    else
    {
        for (int i = startIdx; i < startIdx + k; i++)
            cout << s[i] << " ";
    }

    cout << endl;

    vector<int> arr = {2, 3, 5, 1, 1, 5};
    int ans = findPalindromicSubArray(arr, k);
    cout << "Answer of Apna College code: " << endl;
    if (ans == -1)
        cout << "Palindromic sub array doesn't exist" << endl;
    else
    {
        for (int i = ans; i < ans + k; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    return 0;
}