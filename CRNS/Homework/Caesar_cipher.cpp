#include <bits/stdc++.h>
using namespace std;

/* Encryption using caesar cipher */

string Encrypt(string s, int k)
{
    string answer = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            answer += ' ';
            continue;
        }
        int total_shifts = ((s[i] - 'a') + k) % 26;
        answer += ('a' + total_shifts);
    }
    return answer;
}

/* Decryption using caesar cipher */

string Decrypt(string s, int k)
{
    string answer = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            answer += ' ';
            continue;
        }
        answer += ((s[i] - 'a') - k + 26) % 26 + 'a';
    }
    return answer;
}

int main()
{
    int k;
    string s;
    cout << "Enter the key for encryption " << endl;
    cin >> k;
    getchar();
    cout << "Enter the string " << endl;
    getline(cin, s);
    string encrypted = Encrypt(s,k);
    cout << "Encrypted string is " << endl
         << encrypted << endl;
    cout << "Decrypted string is " << endl
         << Decrypt(encrypted, k);
    return 0;
}