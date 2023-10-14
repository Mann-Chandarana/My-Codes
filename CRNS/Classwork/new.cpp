/* Rail fence cipher */

#include <bits/stdc++.h>
using namespace std;

string Encryption(string s, int n, vector<vector<char>> &table)
{
    int i = 0;
    bool down = true;
    string cipher = "";
    for (int k = 0; k < s.length(); k++)
    {
        table[i][k] = s[k];

        if (down)
        {
            i++;
        }
        else
        {
            i--;
        }
        if (i == n - 1)
            down = false;
        if (i == 0)
            down = true;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (table[i][j] != ' ')
            {
                cipher.push_back(table[i][j]);
            }
        }
    }
    return cipher;
}

void decryption(vector<vector<char>> table, int n)
{
    int i = 0;
    bool down = true;
    string plain = "";
    for (int k = 0; k < table[0].size(); k++)
    {
        plain.push_back(table[i][k]);

        if (down)
        {
            i++;
        }
        else
        {
            i--;
        }
        if (i == n - 1)
            down = false;
        if (i == 0)
            down = true;
    }
    cout << "Decrypted value is " << plain << endl;
}

int main()
{
    string s;
    int key;
    cout << "Enter the string for encryption" << endl;
    getline(cin, s);
    cout << "Enter the key for encryption" << endl;
    cin >> key;
    vector<vector<char>> table(key, vector<char>(s.size(), ' '));
    string cipher = Encryption(s, key, table);
    cout << "Encryption of the plain text is " << cipher << endl;
    decryption(table, key);

    return 0;
}