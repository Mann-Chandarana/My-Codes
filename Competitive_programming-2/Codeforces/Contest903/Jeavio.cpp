#include <bits/stdc++.h>
using namespace std;

int len(string &answer)
{
    stack<char>st;
    int maxi = INT_MIN,count=0;
    
    for(int i=0;i<answer.length();i++)
    {
        if(answer[i]=='<')
          count = 0,st.push(answer[i]);
        else
        {
            if(!st.empty() and st.top()=='<')
            {
                st.pop(),count+=2;
                maxi = max(maxi,count);
            }
        }
    }
    return maxi==INT_MIN?0:maxi;
}

void f(int index, string &answer,int &maxi)
{
    if(index==answer.length())
    {
        maxi = max(maxi,len(answer));
        return;
    }
    
    if(answer[index]=='?')
    {
        answer[index]='<';
        f(index+1,answer,maxi);
        
        answer[index]='>';
        f(index+1,answer,maxi);

        answer[index]='?';
    }
    else
      f(index+1,answer,maxi);
}

int solve(string s)
{
    int answer = INT_MIN;
    f(0,s,answer);
    return answer;
}

int main() 
{
    cout<<solve("<><???>")<<endl;
    return 0;
}