#include <iostream>
#include <string>
#include <algorithm> //to use sort function

using namespace std;
int main()
{
    // string str="Apnikaksha";
    // string str1(5, 'n');
    // cout << str1;
    // cin >> str;
    // cout << str;

    // string str;
    // getline(cin, str);
    // cout<<str;

    // string s1 = "fam";
    // string s2 = "ily";
    // s1.append(s2);
    // cout << s1 + s2 << endl;

    // string abc = "deudu uwbcfwuef";
    // abc.clear();
    // cout << abc;

    // string s1 = "abc";
    // string s2 = "xyz";
    // cout << s2.compare(s1) << endl;

    // string s1 = "jdqeddqew";
    // s1.clear();
    // if (s1.empty())
    // {
    //     cout << "String is empty";
    // }

    // string s1 = "nincompoop";
    // s1.erase(3, 2);
    // cout << s1.find("com");
    // s1.insert(2, "lol");
    // cout << s1.size();
    // cout << s1.length();
    // for (int i = 0; i < s1.length(); i++)
    // {
    //     cout << s1[i] << endl;
    // }
    // string a = s1.substr(6, 4);
    // cout << a << endl;

    // string s1 = "786";
    // int x = stoi(s1);
    // cout << x + 2;

    // int x = 786;
    // cout << to_string(x) + "2" << endl;

    string s1 = "wedcwefcw";
    sort(s1.begin(), s1.end());
    cout << s1 << endl;
    return 0;
}