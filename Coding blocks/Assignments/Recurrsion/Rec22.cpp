//////////// Mapped strings

#include <iostream>
#include <vector>
using namespace std;

char arr[] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'O', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

void code_of_string(string s, string output, int i, int n)
{
    if (s[i] == '\0')
    {
        cout << output << endl;
        return;
    }
    int digit = (s[i] - '0');
    output.push_back(arr[digit]);
    code_of_string(s, output, i + 1, n);
    output.pop_back();

    if ((i + 1 < n))
    {
        int digit2 = (s[i] - '0') * 10 + (s[i + 1] - '0');
        if (digit2 <= 26)
        {
            output.push_back(arr[digit2]);
            code_of_string(s, output, i + 2, n);
            output.pop_back();
        }
    }
}

int main()
{
    string s, out;
    cin >> s;
    code_of_string(s, out, 0, s.length());

    return 0;
}