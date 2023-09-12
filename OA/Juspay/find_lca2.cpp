#include <bits/stdc++.h>
using namespace std;

#define int long long

map<int, int> source_to_root_nodes(int source, vector<int>& parent) {
    map<int, int> path_nodes;
    int h = 0;
    while (source != -1) {
        path_nodes[source] = h++;
        source = parent[source];
    }

    return path_nodes;
}

void solve() {
	int n; cin >> n;
	vector<int> parent(n), root_nodes;
	vector<vector<int>> children(n);
	for (int i = 0; i < n; i++) {
		cin >> parent[i];

		if (parent[i] != -1) {
			children[parent[i]].push_back(i);
		}
		else {
			root_nodes.push_back(i);
		}
	}

	int u, v; cin >> u >> v;

    map<int, int> u_to_root = source_to_root_nodes(u, parent), v_to_root = source_to_root_nodes(v, parent);

    int lca = -1, dist = INT_MAX;
    for (auto it : u_to_root) {
        if (dist > it.second) {
            if (v_to_root.find(it.first) != v_to_root.end()) {
                dist = it.second;
                lca = it.first;
            }
        }
    }

    cout << lca << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) 
        solve();
        
    return 0;
}

/* 
    * do smth instead of nothing and stay organized
    * WRITE STUFF DOWN
    * DON'T GET STUCK ON ONE APPROACH
    * DON'T RUSH, THINK...
*/
		