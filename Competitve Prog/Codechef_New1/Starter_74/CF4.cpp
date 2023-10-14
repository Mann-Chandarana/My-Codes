/* Minimal inversion */

#include<bits/stdc++.h>
#define int long long

using namespace std;
int y2=1e9+7;
int sum=0;
vector<int>p(1e6);
void fac(){
   for(int i=0;i<1e6;i++){
      if(i==0){
        p[i]=1;
      }
      else{
        p[i]=(p[i-1]%y2)*((i+1)%y2);
      }
   }
}
int pow2(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = (res * a);
        a = (a * a);
        b >>= 1;
    }
    return res;
}
void solve(){
    int n;
    cin>>n;
    vector<int>v(n);
    map<int,int>mp1;
    map<int,int>mp;
    for(int i=0;i<n;i++){
      cin>>v[i];
      mp1[v[i]]++;
   }
    vector<int>v2(n+1,0);
    for(int i=n-1;i>=0;i--){
        v2[i]=v2[i+1];
        v2[i]=v2[i]+mp1[v[i]+1];
        v2[i]=v2[i]-mp[v[i]-1];
        mp1[v[i]]--;
        mp[v[i]]++;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,v2[i]);
    }
    cout<<ans;

}

signed main(){
  int t=1;
  cin>>t;
  for(int i=0;i<t;i++){
     solve();
     cout<<"\n";
  }
  return 0;
}