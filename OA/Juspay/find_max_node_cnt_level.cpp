#include <bits/stdc++.h>
using namespace std;

#define int long long

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

	queue<int> q;
	for (int root_node : root_nodes) {
		q.push(root_node);
	}

	int level = 0;
	int max_node_cnt = 0, max_node_cnt_level = 0;
	while (!q.empty()) {
		int sz = q.size();

		if (sz >= max_node_cnt) {
			max_node_cnt = sz;
			max_node_cnt_level = level;
		}
		while (sz--) {
			int curr = q.front();
			q.pop();

			for (int next : children[curr]) {
				q.push(next);
			}
		}
		level++;
	}

	cout << max_node_cnt_level << "\n";
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
		