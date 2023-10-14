#include <iostream>
#include <vector>
using namespace std;
/*
void pushString(string &ans, string word)
{
    if(ans.length() != 0)
        ans.push_back(' '); 
    for(int i=word.length() - 1;i>=0;i--)
        ans.push_back(word[i]);
}

void reverseWords(string &s)
{
    string ans = "", word = "";
    
    for(int i=s.length() - 1;i>=0;i--)
    {
        if(s[i] == ' ')
        {
            pushString(ans, word);
            word = "";
        }
        else
            word.push_back(s[i]);
    }
    
    pushString(ans, word);
    
    s = ans;
}
*/

/*
char getMaxOccurChar(string &s)
{
    int arr[26] = {0};
    
    for(int i=0;i<s.length();i++)
    {
        if(s[i] >= 'a' and s[i] <= 'z')
            arr[s[i] - 'a']++;
        
        else
            arr[s[i] - 'A']++;
    }
    
    int maxInd = 0;
    for(int i=0;i<26;i++)
    {
        if(arr[i] > arr[maxInd])
            maxInd = i;
    }
    
    return maxInd + 'a';
}
*/

int main()
{
    /**
    // char ch[3];
    // cin >> ch;
    // cout << ch << endl;
    // int i=0;
    // ch[1] = '\0';
    // cout << ch << endl;
    // while(ch[i] != '\0')
    //     cout << ch[i++] << " ";
        
    // cout << endl << ch[1] << " " << ch[2];
    
    // // string s;
    // // cin >> s;
    // // cout << s;
    
    // // string s1;
    // // getline(cin, s1);
    // // cout << s1;
    
    // char charArr[20];
    // cin.getline(charArr, 20);
    // cout << charArr;
    
    char a = '5';
    cout << int(a) << endl;
    **/
    
    // string s;
    // getline(cin,s);
    // cout << s << endl;
    // reverseWords(s);
    // cout << s << endl;
    
    
    // string s;
    // cin >> s;
    // cout << getMaxOccurChar(s) << endl;
    
    
    // string s1;
    // string s2;
    // cin >> s1;
    // cin >> s2;
    // // s1.push_back(s2); // will give errors. push_back can push characters only.
    // s1.append(s2); // Append one string at the ned of another
    // cout << s1;
    
    string s = "abcdefghijk";
    s.erase(2,3); // s.erase(x,3) will erase characters from x position to total x + 3 characters.
    cout << s << endl;
    
}
