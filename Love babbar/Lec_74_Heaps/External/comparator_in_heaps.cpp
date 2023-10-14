// #include <iostream>
#include "bits/stdc++.h"

using namespace std;

class info{
    public:
    int a,b,c;
    
    info(int a,int b,int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

class cmpInt{
    public:
    bool operator()(int &a, int &b)
    {
        // return a > b;
        return a < b;
    }
};

class cmpInfo{
    public:
    bool operator()(info *o1, info *o2)
    {
        if(o1->a < o2->a) return true;
        
        if(o1->a == o2->a and o1->b < o2->b) return true;
        
        if(o1->a == o2->a and (o1->b == o2->b and o1->c < o2->c)) return true;
        
        return false;
    }
};

void printHeap(priority_queue<int, vector<int>, cmpInt> pq)
{
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

void insert(priority_queue<info*, vector<info*>, cmpInfo> &pq, int a, int b, int c)
{
    info *temp = new info({a,b,c});
    pq.push(temp);
}

void printHeapWithClass(priority_queue<info*, vector<info*>, cmpInfo> pq)
{
    while(!pq.empty())
    {
        info *temp = pq.top();
        pq.pop();
        
        cout << temp->a << " " << temp->b << " " << temp->c << endl;
    }
}

int main()
{
    priority_queue<int, vector<int>, cmpInt> pq;
    
    pq.push(10);
    pq.push(15);
    pq.push(7);
    pq.push(12);
    pq.push(3);
    pq.push(9);
    pq.push(20);
    pq.push(10);
    
    printHeap(pq);
    
    cout << "Queue with user defined class input objects\n";
    
    priority_queue<info*, vector<info*>, cmpInfo> pq1;
    
    insert(pq1, 10, 20, 30);
    insert(pq1, 10, 10, 30);
    insert(pq1, 10, 12, 3);
    insert(pq1, 1, 2, 3);
    insert(pq1, 10, 2, 30);
    insert(pq1, 1, 20, 30);
    insert(pq1, 1, 2, 30);
    insert(pq1, 100, 2, 30);
    insert(pq1, 100, 200, 300);
    insert(pq1, 10, 12, 4);
    
    printHeapWithClass(pq1);
    
    return 0;
}
