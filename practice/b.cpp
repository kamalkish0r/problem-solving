#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = INT_MAX;
vector<int> bfs(int source, vector<vector<int>>& adj) {
    queue<int> q;
    q.push(source);
    vector<int> dist(adj.size(), INF);
    dist[source] = 0;
    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            int curr = q.front();
            q.pop();

            for (int next : adj[curr]) {
                if (dist[next] == INF) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }
    }

    return dist;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    int a, b, c; cin >> a >> b >> c;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist_a = bfs(a, adj);
    vector<int> dist_b = bfs(b, adj);

    // dist(a -> b) + dist(b -> c) == dist(a -> c)

    cout << (dist_a[b] + dist_b[c] == dist_a[c] ? "Yes\n" : "No\n");

    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/  

    