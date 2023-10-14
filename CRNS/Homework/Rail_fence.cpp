/* Rail fence */

#include <iostream>
#include <math.h>
using namespace std;

string encrypt(string message, int rows)
{
    int len = message.length();

    char matrix[rows][len];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < len; j++)
        {
            matrix[i][j] = '\0';
        }
    }

    int i = 0, j = 0;

    bool alter = false;
    while (j < len)
    {
        matrix[i][j] = message[j];
        j++;

        if (i == rows - 1)
        {
            alter = true;
        }

        if (i == 0)
        {
            alter = false;
        }

        if (alter)
        {
            i--;
        }
        else
        {
            i++;
        }
    }

    string cipher;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (matrix[i][j] != '\0')
            {
                cipher.push_back(matrix[i][j]);
            }
        }
    }

    return cipher;
}

string decrypt(string cipher, int rows)
{
    int len = cipher.length();
    char matrix[rows][len];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < len; j++)
        {
            matrix[i][j] = '\0';
        }
    }

    int i = 0, j = 0;

    bool alter = false;
    while (j < len)
    {
        matrix[i][j] = '*';
        j++;

        if (i == rows - 1)
        {
            alter = true;
        }

        if (i == 0)
        {
            alter = false;
        }

        if (alter)
        {
            i--;
        }
        else
        {
            i++;
        }
    }

    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (matrix[i][j] == '*')
            {
                matrix[i][j] = cipher[k++];
            }
        }
    }

    string message;
    i = 0, j = 0;
    alter = false;
    while (j < len)
    {
        message.push_back(matrix[i][j]);
        j++;

        if (i == rows - 1)
        {
            alter = true;
        }

        if (i == 0)
        {
            alter = false;
        }

        if (alter)
        {
            i--;
        }
        else
        {
            i++;
        }
    }
    return message;
}

int main()
{
    string cipher = encrypt("Hello World", 3);
    cout << cipher << endl;
    cout << decrypt(cipher, 3) << endl;
    
    return 0;
}