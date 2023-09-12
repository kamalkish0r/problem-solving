#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 1e15;
vector<int> dijkstra(int source, vector<vector<int>>& adj) {
	vector<int> dist(adj.size(), INF);
	dist[source] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({dist[source], source});

	while (!pq.empty()) {
		auto it = pq.top();
		pq.pop();

		if (dist[it.second] != it.first) {
			continue;
		}

		for (int next : adj[it.second]) {
			if (dist[next] > dist[it.second] + 1) {
				dist[next] = dist[it.second] + 1;
				pq.push({dist[next], next});
			}
		}
	}

	return dist;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for (int prev = 0; prev < n; prev++) {
    	int next; cin >> next;
    	if (next != -1)
    		adj[prev].push_back(next);
    }

    int c1, c2;
    cin >> c1 >> c2;

    vector<int> dist1 = dijkstra(c1, adj), dist2 = dijkstra(c2, adj);
    int min_dist = INF, min_dist_node = -1;
    for (int i = 0; i < n; i++) {
    	if (dist1[i] != INF and dist2[i] != INF) {
    		if (min_dist > dist1[i] + dist2[i]) {
    			min_dist = dist1[i] + dist2[i];
    			min_dist_node = i;
    		}
    	}
    }

    cout << min_dist_node << "\n";

    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/  

	