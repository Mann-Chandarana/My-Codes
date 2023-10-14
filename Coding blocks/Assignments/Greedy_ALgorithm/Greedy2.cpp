////////  Expedi

#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first > p2.first;
}

int main()
{
    int n, distance, fuel, D, F;
    int flag = 0;
    cin >> n;
    priority_queue<int> pq;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        cin >> distance >> fuel;
        v.push_back({distance, fuel});
    }
    sort(v.begin(), v.end(), compare);

    cin >> D >> F;
    for (int i = 0; i < n; i++)
    {
        v[i].first = D - (v[i].first);
    }
    int ans = 0;

    // prev for previous location
    // x for current location
    int prev = 0, x = 0;

    while (x < n)
    {
        if (F >= v[x].first - prev)
        {
            F -= (v[x].first - prev);
            pq.push(v[x].second);
            prev = v[x].first;
        }
        else
        {
            if (pq.empty())
            {
                flag = -1;
                break;
            }
            else
            {
                F += pq.top();
                pq.pop();
                ans += 1;
                continue;
            }
        }
        x++;
    }

    if (flag == -1)
    {
        flag = 40;
        cout << -1 << endl;
    }
    else
    {
        D = D - v[n - 1].first;
        if (F >= D)
        {
            cout << ans << endl;
        }
        while (F < D)
        {
            if (pq.empty())
            {
                flag = 10;
                break;
            }
            F += pq.top();
            pq.pop();
            ans += 1;
        }

        if (flag == 10)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << ans << endl;
        }
    }

    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// bool compare(pair<int,int> v1,pair<int,int> v2)
// {
// 	return v1.first<v2.first;
// }
// int main () {
// 	int n;
// 	cin>>n;
// 	vector<pair<int,int> > v;
// 	int d,f;
// 	for(int i=0;i<n;i++)
// 	{
// 		cin>>d>>f;
// 		v.push_back(make_pair(d,f));
// 	}
// 	int L,P;
// 	cin>>L>>P;
	
// 	for(int i=0;i<n;i++)
// 		v[i].first=L-v[i].first;
	
// 	sort(v.begin(),v.end(),compare);

// 	int x=0,prev=0,ans=0;
// 	priority_queue<int> pq;
// 	int flag=0;

// 	while(x<n)
// 	{
// 		if(P>=v[x].first-prev)
// 		{
// 			P-=v[x].first-prev;
// 			pq.push(v[x].second);
// 			prev=v[x].first;
// 		}

// 		else
// 		{
// 			if(pq.empty())
// 			{
// 				flag=-1;
// 				break;
// 			}
// 			else
// 			{
// 				P+=pq.top();
// 				pq.pop();
// 				ans++;
// 				continue;
// 			}
// 		}
// 		x++;
// 	}
// 	if(flag==-1)
// 		cout<<-1;
// 	else 
// 	{
// 		L-=v[n-1].first;
// 		if(P>=L)
// 		{
// 			flag=40; cout<<ans;
// 		}
// 		else{
// 			while(P<L)
// 			{
// 				if(pq.empty())
// 				{
// 					flag=10;
// 					break;
// 				}
// 				else{
// 					P+=pq.top();
// 					pq.pop();
//                     ans++;
// 				}
// 			}
// 			if(flag==10)
// 				cout<<-1;
// 			else cout<<ans;			
// 		}
// 	}
	
	
// 	return 0;
// }