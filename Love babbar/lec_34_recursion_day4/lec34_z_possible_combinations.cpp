#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> arr,int start,vector<int> &v)
{
    if(start == arr.size())
    {
        for(int i=0;i<v.size();i++) cout << v[i] << " ";
        cout << endl;
        return;
    }
    
    v.push_back(arr[start]);
    print(arr,start+1,v);
    v.pop_back();
    print(arr,start+1,v);
}

void printString(string s,int start, string &temp)
{
    if(start == s.length())
    {
        cout << temp << endl;
        return;
    }
    
    temp += s[start];
    printString(s,start + 1,temp);
    temp.erase(temp.begin() + temp.length() - 1);
    printString(s,start + 1,temp);
}

int main()
{
    vector<int> arr = {1,2,3,4};
    // vector<int> v;
    // int start = 0;
    // print(arr,start,v);
    
    string s = "abcd";
    string temp = "";
    int start = 0;
    printString(s,start,temp);


    cout << "Main end.." << endl;
    return 0;
}
