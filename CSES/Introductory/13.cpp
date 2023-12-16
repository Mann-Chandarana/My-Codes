/* Tower of Hanoi */

#include <bits/stdc++.h>
using namespace std;

#define fastread()  (ios_base:: sync_with_stdio(false),cin.tie(NULL))

void towerOfHanoi(int n,int source,int auxilary,int destination)
{
    if(n==0)
      return;
    
    towerOfHanoi(n-1,source,destination,auxilary);
    cout<<source<<" "<<destination<<endl;
    towerOfHanoi(n-1,auxilary,source,destination);
}

void solve(int n)
{
   towerOfHanoi(n,1,2,3);
}

int main()
{
    fastread();

    int n;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    solve(n);

    return 0;
}