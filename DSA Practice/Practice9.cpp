#include <iostream>
#include <stack>
using namespace std;

void reverse(string s)
{
    stack<string> sp;
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        sp.push(word);
    }
    while (!sp.empty())
    {
        cout << sp.top() << " ";
        sp.pop();
    }
}
int main()
{
    string s;
    getline(cin,s);
    
    reverse(s);
    return 0;
}