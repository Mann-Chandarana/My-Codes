#include<iostream>
using namespace std;

void dec(int n){

    if(n==1){
        cout<<n;
        return;
    }

    cout<<n<<" ";
    dec(n-1);
}

void inc(int n){

    if(n==1){
        cout<<n<<" ";
        return;
    }

    inc(n-1);
    cout<<n<<" ";
    
}

int main(){
    int n;
    cin>>n;

    dec(n);
    cout<<endl;
    inc(n);

    return 0;
}