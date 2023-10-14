#include <iostream>
using namespace std;
int main()
{
    int t,n,i,j,sum;
    cin >> t;
    while(t--)
    {
        sum=0;
        cin >> n;
        int d[n];
        for(i=0;i<n;i++)
        {
            cin >> d[i];
        }
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(d[j]==d[i])
                {
                    d[j]=0;
                }
            }
        }
        for(i=0;i<n;i++)
        {
            if(d[i]!=0)
            {
                sum++;
            }
        }
        cout << sum << endl;
    }
}

