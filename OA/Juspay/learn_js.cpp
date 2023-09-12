	#include <bits/stdc++.h>
	using namespace std;

	#define int long long

	const int INF = 1e17;
	int find_shortest_dist(int source, int destination, vector<vector<pair<int, int>>>& adj) {
		int n = adj.size();
		vector<int> dist(n, INF);
		dist[source] = 0;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		pq.push({dist[source], source});

		while (!pq.empty()) {
			auto curr = pq.top();
			pq.pop();

			int d = curr.first, u = curr.second;
			if (dist[u] != d) {
				continue;
			}

			for (auto &next : adj[u]) {
				int v = next.first, weight = next.second;
				if (dist[v] > dist[u] + weight) {
					dist[v] = dist[u] + weight;
					pq.push({dist[v], v});
				}
			}
		}

		return dist[destination];
	}

	signed main() {
	    ios::sync_with_stdio(false);
	    cin.tie(0);
	    
	    int n; cin >> n;
	    map<int, int> node_at_id;
	    for (int i = 0; i < n; i++) {
	    	int member_id; cin >> member_id;
	    	node_at_id[member_id] = i;
	    }

	    int m; cin >> m;
	    vector<vector<pair<int, int>>> adj(n);
	    for (int i = 0; i < m; i++) {
	    	int u, v, weight; cin >> u >> v >> weight;
	    	adj[node_at_id[u]].push_back({node_at_id[v], weight});
	    }

	    int source, destination;
	    cin >> source >> destination;

	    cout << find_shortest_dist(node_at_id[source], node_at_id[destination], adj) << "\n";

	    return 0;
	}

	/* 
	    * do smth instead of nothing and stay organized
	    * WRITE STUFF DOWN
	    * DON'T GET STUCK ON ONE APPROACH
	    * DON'T RUSH, THINK...
	*/  

