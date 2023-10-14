////////// Religious People

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

class DSU
{
public:
    ll Find(ll i, ll *parent)
    {
        if (parent[i] == -1)
        {
            return i;
        }
        return parent[i] = Find(parent[i], parent);
    }

    void Merge_two(ll x, ll y, ll *parent, ll *rank)
    {
        ll s1 = Find(x, parent);
        ll s2 = Find(y, parent);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph
{
    vector<pair<ll, ll>> adj;
    ll V;

public:
    Graph(ll V)
    {
        this->V = V;
    }

    void addEdge(ll u, ll v)
    {
        adj.push_back(make_pair(u - 1, v - 1));
    }

    ll components()
    {
        DSU D;
        ll *parent = new ll[V];
        ll *rank = new ll[V];

        for (ll i = 0; i < V; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }

        for (auto ele : adj)
        {
            ll s1 = D.Find(ele.first, parent);
            ll s2 = D.Find(ele.second, parent);

            D.Merge_two(ele.first, ele.second, parent, rank);
        }

        map<ll, ll> mp;
        for (ll i = 0; i < V; i++)
        {
            // cout << parent[i] << " ";
            if (parent[i] != -1)
            {
                mp[parent[i]]++;
            }
        }
        // cout << endl;
        // cout << mp.size() << endl;
        delete[] parent;
        delete[] rank;
        return mp.size();
    }
};

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll N, M, A, B, u, v;
        cin >> N >> M >> A >> B;
        map<ll, ll> mp;
        Graph g(N);
        for (ll i = 0; i < M; i++)
        {
            cin >> u >> v;
            mp[u]++;
            mp[v]++;
            g.addEdge(u, v);
        }

        if (A < B)
        {
            cout << A * N << endl;
        }
        else
        {
            ll ans = 0;
            ll components = g.components();
            ll V = mp.size();
            int not_connected = N - V;
            ans += components * A + (N - components - (not_connected)) * B + (not_connected)*A;
            cout << ans << endl;
        }
    }

    return 0;
}

//////////////// Second approach

// #include<bits/stdc++.h>

// #define fast ios::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr);
// #define ll long long

// using namespace std;

// class graph {
// 	unordered_map<ll, list<ll>> adjList;

//   public:

// 	void insert(ll u, ll v) {
// 		adjList[u].push_front(v);
// 		adjList[v].push_front(u);
// 	}

// 	ll bfs(ll src, vector<ll>& visited) {

// 		queue<ll> q;
// 		ll roads = 0;
// 		visited[src] = true;
// 		q.push(src);

// 		while (!q.empty()) {
// 			ll node = q.front();
// 			q.pop();

// 			for (auto padosi : adjList[node]) {
// 				if (!visited[padosi]) {
// 					visited[padosi] = true;
// 					q.push(padosi);
// 					roads++;
// 				}
// 			}
// 		}

// 		return roads;
// 	}

// 	ll religiousPeople(ll n, ll tempCost, ll roadCost) {
// 		if (tempCost < roadCost)
// 			return (tempCost * n);

// 		ll cost = 0;
// 		vector<ll> visited(n + 1, false);

// 		for (auto ele : adjList) {
// 			ll node = ele.first;
// 			if (!visited[node]) {
// 				cost += (bfs(node, visited) * roadCost) + tempCost;
// 			}
// 		}

// 		for (ll i = 1; i <= n; i++)
// 			if (!visited[i])
// 				cost += tempCost;

// 		return cost;
// 	}
// };
// int main() {
// 	fast
// 	ll t;
// 	cin >> t;
// 	while (t--) {
// 		graph g;
// 		ll n, e, tempCost, roadCost;
// 		cin >> n >> e >> tempCost >> roadCost;
// 		while (e--) {
// 			ll u, v;
// 			cin >> u >> v;
// 			g.insert(u, v);
// 		}
// 		cout << g.religiousPeople(n, tempCost, roadCost) << endl;
// 	}

// }