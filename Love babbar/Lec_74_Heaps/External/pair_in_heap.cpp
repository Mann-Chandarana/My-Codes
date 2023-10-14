/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream>
#include <queue>
// #include <pair>

using namespace std;

#define pii pair<int, int>

int main()
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // In first first check is done on first ele of pair.
    // if pair.first is same for two elements then only checked for second element

    pq.push(make_pair(2,6));
    pq.push(make_pair(4,1));
    
    cout << pq.top().first << " " << pq.top().second << endl;
    
    pq.push(make_pair(2,3));
    
    cout << pq.top().first << " " << pq.top().second << endl;
    
    pq.push(make_pair(100,-60));
    cout << pq.top().first << " " << pq.top().second << endl;
    
    pq.push(make_pair(2,16));
    cout << pq.top().first << " " << pq.top().second << endl;
    
    pq.push(make_pair(2,-6));
    cout << pq.top().first << " " << pq.top().second << endl;
    
    return 0;
}
