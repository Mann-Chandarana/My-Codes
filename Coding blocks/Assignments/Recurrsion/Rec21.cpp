/////////////// Convert a string to a integer

#include <iostream>
using namespace std;

int string_to_int(string s, int n)
{
    if (n == 0)
    {
        return 0;
    }
    int smallerAns = (s[n - 1] - '0');
    int largerAns = string_to_int(s, n - 1);
    return largerAns * 10 + smallerAns;
}

int main()
{
    string s;
    cin >> s;

    int n = string_to_int(s, s.length());
    cout << n << endl;
    return 0;
}